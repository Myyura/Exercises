/**
 * Candy
 * Myyura
 */

/**
 * There are N children standing in a line. Each child is assigned a rating value.
 * 
 * You are giving candies to these children subjected to the following requirements:
 * 
 * Each child must have at least one candy.
 * Children with a higher rating get more candies than their neighbors.
 * What is the minimum candies you must give?
 * 
 * Example 1:
 * Input: [1,0,2]
 * Output: 5
 * Explanation: You can allocate to the first, second and third child with 2, 1, 
 * 2 candies respectively.
 * 
 * Example 2:
 * Input: [1,2,2]
 * Output: 4
 * Explanation: You can allocate to the first, second and third child with 1, 2, 
 * 1 candies respectively. The third child gets 1 candy because it satisfies the 
 * above two conditions.
 */

class Solution {
public:
    /**
     * The idea of the algorithm is simplely from the two rules -- if one child's
     * rating is higher than his neighbor, than he should get one more candy than
     * his neighbor. And it is obviously that every child with minimum rating 
     * should gets only 1 candy. Hence we can start with such children,
     * 
     * Note that the candies that are assigned to every part between two minimum 
     * rating children can be decided distinctly.
     */
    int candy(std::vector<int>& ratings) {
        if (ratings.size() == 0) { return 0; }
        
        std::vector<int> candies(ratings.size(), 1);
        int min_rating = 0xFFFFFFF;
        for (int i = 0; i < ratings.size(); i++) {
            if (min_rating > ratings[i]) { min_rating = ratings[i]; }
        }
        
        int last_min_rating_index = -1;
        for (int i = 0; i < ratings.size(); i++) {
            if (ratings[i] == min_rating || i == ratings.size() - 1) {
                for (int j = last_min_rating_index + 1; j <= i; j++) {
                    if (j == 0) { continue; }
                    if (ratings[j] > ratings[j - 1]) { candies[j] = candies[j - 1] + 1; }
                }
                
                /**
                 * There may exists some children whose rating is higher than both
                 * his neighbors', since we don't really know who of his neighbor 
                 * has more candies, we need a two-way check.
                 */
                for (int j = i - 1; j >= last_min_rating_index; j--) {
                    if (ratings[j] > ratings[j + 1] && candies[j] <= candies[j + 1]) { 
                        candies[j] = candies[j + 1] + 1; 
                    }
                }
                last_min_rating_index = i;
            }
        }
        
        int total_candies = 0;
        for (auto candy : candies) { total_candies += candy; }
        return total_candies;
    }
};