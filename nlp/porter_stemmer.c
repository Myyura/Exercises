#include <string.h>

struct stemmer;
typedef struct stemmer stem_t;

struct stemmer {
    char *word;
    int len;
    int stem_offset;
};


/*
 * A 'consonant' in a word is a letter other than A, E, I, O or U, and other
 * than Y preceded by a consonant. (The fact that the term `consonant' is
 * defined to some extent in terms of itself does not make it ambiguous.) So in
 * TOY the consonants are T and Y, and in SYZYGY they are S, Z and G. If a
 * letter is not a consonant it is a 'vowel'.
 */
static int is_constant(stem_t *w, int i) {
    switch(w->word[i]) {
    case 'a':
    case 'e':
    case 'i':
    case 'u':
    case 'o': return 0;

    case 'y': return (i == 0) ? 1 : !is_constant(w, i - 1);
    defalut: return 1;
    }
}

/*
 * calc_m(w) measures the number of consonant sequences between 0 and stem_offset - 1.
 * a consonant sequence and v a vowel sequence, and <..> indicates arbitrary
 * presence,
 *
 * <c><v>       gives 0
 * <c>vc<v>     gives 1
 * <c>vcvc<v>   gives 2
 * <c>vcvcvc<v> gives 3
 * ......
 */
static int calc_m(stem_t *w) {
    int m = 0;
    int i = 0;
    // pass the first <c>
    for(; ; i++) {
        if(i > w->stem_offset) { return m; }
        if(!is_constant(w, i)) { break; }
    }

    i++;
    for(; ; i++) {
        // pass v
        while(1) {
            if(i > w->stem_offset) { return m; }
            if(is_constant(w, i)) { break; }
            i++;
        }

        i++, m++;
        // pass c
        while(1) {
            if(i > w->stem_offset) { return m; }
            if(!is_constant(w, i)) { break; }
            i++;
        }
    }
}

/* vowel_in_stem(w) returns 1 if 0,...stem_offset contains a vowel */
static int vowel_in_stem(stem_t *w) {
    for(int i = 0; i <= w->stem_offset; i++) {
        if(!is_constant(w, i)) { return 1; }
    }

    return 0;
}

/* double_c(z, j) returns 1 if j,(j - 1) contain a double consonant. */
static int double_c(stem_t *w, int j) {
    if(j < 1 || w->len < j) {
        return 0;
    }

    if(w->word[j] != w->word[j - 1]) {
        return 0;
    }

    return is_constant(w, j);
}

/*
 * cvc(w, j) returns 1 <=> j-2,j-1,j has the form consonant - vowel - consonant
 * and also if the second c is not w,x or y. this is used when trying to
 * restore an e at the end of a short word. e.g.
 *
 * cav(e), lov(e), hop(e), crim(e), but
 * snow, box, tray.
 */
static int cvc(stem_t *w, int j) {
    if(j  < 2 || !is_constant(w, j) || is_constant(w, j - 1) || !is_constant(w, j - 2)) {
        return 0;
    }

    int ch = w->word[j];
    if (ch  == 'w' || ch == 'x' || ch == 'y') {
        return 0;
    }

    return 1;
}

/* ends(w, s) returns 1 if 0,...len - 1 ends with the string s.*/
static int ends(stem_t *w, char *s) {
    int len = strlen(s);
    if(s[len - 1] != w->word[w->len - 1]) { return 0; }
    if(len > w->len) { return 0; }
    for(int i = len - 1, j = w->len - 1; i >= 0; i--, j--) {
        if(w->word[j] != s[i]) {
            return 0;
        }
    }

    w->stem_offset = w->len - len - 1;
    return 1;
}

/*
 * set_to(w, s) sets (j+1),...len - 1 to the characters in the string s,
 * readjusting len.
 */
static void set_to(stem_t *w, char *s) {
    int len = strlen(s);
    int i = w->stem_offset + 1;
    for(int j = 0; s[j] != '\0'; i++, j++) {
        w->word[i] = s[j];
    }
    w->word[i] = '\0';
    w->len = w->stem_offset + len + 1;
}

/* r(w, s) is used further down. */
static void r(stem_t *w, char *s) {
    if(calc_m(w) > 0) { set_to(w, s); }
}

/* step1_ab(w) gets rid of plurals and -ed or -ing. e.g.

       caresses  ->  caress
       ponies    ->  poni
       ties      ->  ti
       caress    ->  caress
       cats      ->  cat

       feed      ->  feed
       agreed    ->  agree
       disabled  ->  disable

       matting   ->  mat
       mating    ->  mate
       meeting   ->  meet
       milling   ->  mill
       messing   ->  mess

       meetings  ->  meet

*/
static void step1_ab(stem_t *w) {
    if(w->word[w->len - 1] == 's') {
        if(ends(w, "sses")) {
            w->len -= 2;
        } else if(ends(w, "ies")) {
            set_to(w, "i");
        } else if(w->word[w->len -2] != 's') {
            w->len--;
        }
    }

    if(ends(w, "eed")) {
        if(calc_m(w) > 0) { w->len--; }
    } else if((ends(w, "ed") || ends(w, "ing")) && vowel_in_stem(w)) {
        w->len = w->stem_offset + 1;
        if(ends(w, "at")) {
            set_to(w, "ate");
        } else if(ends(w, "bl")) {
            set_to(w, "ble");
        } else if(ends(w, "iz")) {
            set_to(w, "ize");
        } else if(double_c(w, w->len - 1)) {
            w->len--;
            int ch = w->word[w->len - 1];
            if(ch == 'l' || ch == 's' || ch == 'z') { w->len++; }
        } else if(calc_m(w) == 1 && cvc(w, w->len - 1)) {
            set_to(w, "e");
        }
    }
}

/* step1_c(w) turns terminal y to i when there is another vowel in the stem. */
static void step1_c(stem_t *w) {
    if(ends(w, "y") && vowel_in_stem(w)) { w->word[w->len - 1] = 'i'; }
}

/*
 * step2(w) maps double suffices to single ones. so -ization ( = -ize plus
 * -ation) maps to -ize etc. note that the string before the suffix must give
 * calc_m(w) > 0.
 */
static void step2(stem_t *w) {
    switch(w->word[w->len - 2]) {
    case 'a':
    {
        if(ends(w, "ational")) { r(w, "ate"); break; }
        if(ends(w, "tional")) { r(w, "tion"); break; }
        break;
    }
    case 'c':
    {
        if(ends(w, "enci")) { r(w, "ence"); break; }
        if(ends(w, "anci")) { r(w, "ance"); break; }
        break;
    }
    case 'e':
    {
        if(ends(w, "izer")) { r(w, "ize"); break; }
        break;
    }
    case 'l':
    {
        if(ends(w, "bli")) { r(w, "ble"); break; }
        if(ends(w, "alli")) { r(w, "al"); break; }
        if(ends(w, "entli")) { r(w, "ent"); break; }
        if(ends(w, "eli")) { r(w, "e"); break; }
        if(ends(w, "ousli")) { r(w, "ous"); break; }
        break;
    }
    case 'o':
    {
        if(ends(w, "ization")) { r(w, "ize"); break; }
        if(ends(w, "ation")) { r(w, "ate"); break; }
        if(ends(w, "ator")) { r(w, "ate"); break; }
        break;
    }
    case 's':
    {
        if(ends(w, "alism")) { r(w, "al"); break; }
        if(ends(w, "iveness")) { r(w, "ive"); break; }
        if(ends(w, "fulness")) { r(w, "ful"); break; }
        if(ends(w, "ousness")) { r(w, "ous"); break; }
        break;
    }
    case 't':
    {
        if(ends(w, "aliti")) { r(w, "al"); break; }
        if(ends(w, "iviti")) { r(w, "ive"); break; }
        if(ends(w, "biliti")) { r(w, "ble"); break; }
        break;
    }
    case 'g': if(ends(w, "logi")) { r(w, "log"); break; }
    }
}

/* step3(w) deals with -ic-, -full, -ness etc. similar strategy to step2. */
static void step3(stem_t *w) {
    switch(w->word[w->len - 1]) {
    case 'e':
    {
        if(ends(w, "icate")) { r(w, "ic"); break; }
        if(ends(w, "ative")) { r(w, ""); break; }
        if(ends(w, "alize")) { r(w, "al"); break; }
        break;
    }
    case 'i': if(ends(w, "iciti")) { r(w, "ic"); break; } break;
    case 'l':
    {
        if(ends(w, "ical")) { r(w, "ic"); break; }
        if(ends(w, "ful")) { r(w, ""); break; }
        break;
    }
    case 's': if(ends(w, "ness")) { r(w, ""); break; } break;
    }
}

/* step4(w) takes off -ant, -ence etc., in context <c>vcvc<v>. */
static void step4(stem_t *w) {
    switch(w->word[w->len -2]) {
    case 'a': if(ends(w, "al")) break; return;
    case 'c':
    {
        if(ends(w, "ance")) break;
        if(ends(w, "ence")) break; return;
    }
    case 'e': if(ends(w, "er")) break; return;
    case 'i': if(ends(w, "ic")) break; return;
    case 'l':
    {
        if(ends(w, "able")) break;
        if(ends(w, "ible")) break; return;
    }
    case 'n':
    {
        if(ends(w, "ant")) break;
        if(ends(w, "ement")) break;
        if(ends(w, "ment")) break;
        if(ends(w, "ent")) break; return;
    }
    case 'o':
    {
        if(ends(w, "ion") && w->stem_offset >= 0 && (w->word[w->stem_offset] == 's' || w->word[w->stem_offset] == 't')) {
            break;
        }
        if(ends(w, "ou")) break; return;
    }
    case 's': if(ends(w, "ism")) break; return;
    case 't':
    {
        if(ends(w, "ate")) break;
        if(ends(w, "iti")) break; return;
    }
    case 'u': if (ends(w, "ous")) break; return;
    case 'v': if (ends(w, "ive")) break; return;
    case 'w': if (ends(w, "ize")) break; return;
    default: return;
    }

    if (calc_m(w) > 1) w->len = w->stem_offset + 1;
}

/*
 * step5(w) removes a final -e if calc_m(w) > 1, and changes -ll to -l if
 * calc_m(w) > 1.
 */
static void step5(stem_t *w) {
    w->stem_offset = w->len - 1;
    if(w->word[w->len - 1] == 'e') {
        int a = calc_m(w);
        if(a > 1 || a == 1 && !cvc(w, w->len - 2)) { w->len--; }
    }

    if(w->word[w->len - 1] == 'l' && double_c(w, w->len - 1) && calc_m(w) > 1) {
        w->len--;
    }
}

/* In stem(z, b, k), b is a char pointer, and the string to be stemmed is
   from b[0] to b[k] inclusive.  Possibly b[k+1] == '\0', but it is not
   important. The stemmer adjusts the characters b[0] ... b[k] and returns
   the new end-point of the string, k'. Stemming never increases word
   length, so 0 <= k' <= k.
*/

int stem(stem_t *w, char *s, int len) {
   if(len <= 1) return len; /*-DEPARTURE-*/
   w->word = s; w->len = len; /* copy the parameters into w */

   /*
    * With this line, strings of length 1 or 2 don't go through the
    * stemming process, although no mention is made of this in the
    * published algorithm. Remove the line to match the published
    * algorithm.
    */

   step1_ab(w);
   if (w->len > 1) {
      step1_c(w);
      step2(w);
      step3(w);
      step4(w);
      step5(w);
   }

   return w->len;
}
