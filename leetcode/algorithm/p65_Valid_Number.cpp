/**
 * Valid Number
 * Myyura
 */

/**
 * Validate if a given string is numeric.
 * 
 * Some examples:
 * "0" => true
 * " 0.1 " => true
 * "abc" => false
 * "1 a" => false
 * "2e10" => true
 * 
 * Note: It is intended for the problem statement to be ambiguous. You should 
 * gather all requirements up front before implementing one.
 * 
 * Update (2015-02-10):
 * The signature of the C++ function had been updated. If you still see your 
 * function signature accepts a const char * argument, please click the reload 
 * button to reset your code definition.
 */

/**
 * Author: wangxinbo
 * 
 * Use Deterministic Finite Automata method.
 * Define input types:
 * (1) T0: Digit: 0-9
 * (2) T1: Sign: '+', '-'
 * (3) T2: 'e'
 * (4) T3: '.'
 * (5) T4: Blank
 * (6) T5: Others
 * 
 * Define states:
 * (1) Q0: initial states; can accept digit (go to Q2), sign (go to Q1), '.' (has 
 * not found any digit, so go to Q3), blank (stay at Q0), other input lead to 
 * rejection;
 * 
 * (2) Q1: find sign at the beginning; can accept digit (go to Q2), '.' (has not 
 * found any digit, so go to Q3), other input lead to rejection;
 * 
 * (3) Q2: find digit, but has not found '.'; can accept digit (stay at Q2), 'e' 
 * (go to Q5), '.' (now find digit, can go to Q4), blank (go to Q8), other input 
 * lead to rejection;
 * 
 * (4) Q3: find '.', but has not found any digit; can only accept digit (find 
 * digit, now can go to Q4), other input lead to rejection;
 * 
 * (5) Q4: find '.', and has already find some digits; can accept digit (stay 
 * at Q4), 'e' (go to Q5), blank (go to Q8), other input lead to rejection;
 * 
 * (6) Q5: find 'e'; can accept digit (digit before 'e' and after 'e' can lead 
 * to different states, so go to Q7), sign (sign before 'e' and after 'e' can 
 * lead to different states, so go to Q6), other input lead to rejection;
 * 
 * (7) Q6: find sign after e; can only accept digit (go to Q7), other input lead 
 * to rejection;
 * (8) Q7: find digit after e; can accept digit (stay at Q7), and blank (go to 
 * Q8) and
 * 
 * (9) Q8: find blank; can only accept blank (Q8), other input lead to rejection.
 */

class Solution {
public:
    bool isNumber(std::string s) {
        int state = 0;
        std::vector<std::vector<int>> transTable = {
            {2, 1, -1, 3, 0, -1}, // Q0
            {2, -1, -1, 3, -1, -1}, // Q1
            {2, -1, 5, 4, 8, -1}, // Q2
            {4, -1, -1, -1, -1, -1}, // Q3
            {4, -1, 5, -1, 8, -1}, // Q4
            {7, 6, -1, -1, -1, -1}, // Q5
            {7, -1, -1, -1, -1, -1}, // Q6
            {7, -1, -1, -1, 8, -1}, // Q7
            {-1, -1, -1, -1, 8, -1} // Q8
        };
        std::bitset<9> validStates("110010100"); 
        for(char c : s) {
            int type = inputType(c);
            state = transTable[state][type];
            if(state == -1) { return false; }
        }
        return validStates[state];
    }
    
    int inputType(char c) { // use type ID as index to get next state in the transition table.
        if(isdigit(c)) { return 0; } // T0
        if(c == '+' || c == '-') { return 1; } // T1
        if(c == 'e') { return 2; } // T2
        if(c == '.') { return 3; } // T3
        if(c == ' ') { return 4; } // T4
        else { return 5 }; // T5
    }
};