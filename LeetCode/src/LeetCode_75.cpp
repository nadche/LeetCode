#include <iostream> 
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <math.h>

// 49. Group Anagrams
namespace GroupAnagrams {
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs){
        std::vector<std::vector<std::string>> values;
        std:: unordered_map<std::string, std::vector<std::string>> dict;

        for (std::string str : strs){
            std::string counter = "00000000000000000000000000";
            for (const char chr : str){
                counter[chr-'a']++;
            }
            dict[counter].push_back(str);
        }
        for (auto kv : dict){
            values.push_back((std::vector<std::string>) kv.second);
        }
        return values;
    }


    void print(const std::vector<std::vector<std::string>>& out) {
        std::cout << "[";
        for (const std::vector<std::string>& v : out) {
            std::cout << "[";
            for (const std::string& str: v) {
                std::cout << str << " ";
            }
            std::cout << "]";
        }
        std::cout << "]\n";        
    }

    void example() {
        std::vector<std::string> in = {"a"};
        print(groupAnagrams(in));
    }

};
//// 238. Product of Array Except Self
namespace ProductExceptSelf {
    std::vector<int> productExceptSelf(std::vector<int>& nums) {
        
        int n = nums.size();
        std::vector<int> res(n);
        res.reserve(n);
        
        int prefix = 1;
        for (int i = 0; i < n; i++) {
            res[i] = prefix;
            prefix *= nums[i];
        }
        
        int suffix = 1;
        for (int i = n - 1; i >= 0; i--) {
            res[i] *= suffix;
            suffix *= nums[i];
        }
        
        return res;
    }
    void print(const std::vector<int>& out) {
        std::cout << "[";
        for (int i : out) {
            std::cout << i << " ";
        }
        std::cout << "]\n";
    }

    void example() {
        std::vector<int> in = { 1,2,3,4 };
        print(productExceptSelf(in));
    }
};
// 347. Top K Frequent Elements
namespace TopKFrequent{
    std::vector<int> topKFrequent(std::vector<int>& nums, int k ){
        std::unordered_map<int, int> ans;
        for (int n : nums){
            ans[n]++;
        }
        std::vector<int> keys;
        for (auto kv: ans){
            keys.push_back(kv.first);
        }
        sort(keys.begin(), keys.end(), 
        [&ans](int key1, int key2){return (ans[key1]>=ans[key2]); });

        std::vector<int> res;
        for (std::vector<int>::iterator iter = keys.begin(); iter<keys.begin()+k ; iter++){
            res.push_back(*iter);
        }
        return res;
    }
    std::vector<int> topKFrequentv2(std::vector<int>& nums, int k) {
        std::unordered_map<int, int> map;
        for (int num : nums) {
            map[num]++;
        }

        std::vector<int> res;
        // pair<first, second>: first is frequency,  second is number
        std::priority_queue<std::pair<int, int>> pq;
        for (auto it = map.begin(); it != map.end(); it++) {
            pq.push(std::make_pair(it->second, it->first));
            if (pq.size() > (int)map.size() - k) {
                res.push_back(pq.top().second);
                pq.pop();
            }
        }
        return res;
    }
    void print(const std::vector<int>& out) {
        std::cout << "[";
            for (int i : out) {
                std::cout << i << " ";
            }
            std::cout << "]\n";
    }

    void example() {
        std::vector<int> in = { 1,1,1,2,2,3 }; int k = 2;
        print(topKFrequent(in, k));
    }
};
//// 33. Search in Rotated Sorted Array
namespace SearchInRotatedSortedArray{
    int search(std::vector<int>& nums, int target){
        int n= nums.size();
        int i = n-2;
        for (i; i>=0; i--){
            if (nums[i]> nums[i-1])
                break;            
        }
        int low = i;
        int high =(i + n - 1);
        while(low <= high){
            int middle = ((high + low)/2);
            if (nums[middle%n] == target) return middle%n;
            if (nums[middle%n] < target) {high = middle - 1;}
            else low = middle + 1;
        }
        return -1 ;
    }
    void print(const int out) {
            std::cout << out << "\n";
    }

    void example() {
        std::vector<int> in = { 4,5,6,7,0,1,2 };
        print(search(in, 0));
    }

};
//704. Binary Search
namespace BinarySpace {
    int search(std::vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        while (l <= r)
        {
            int m = l + std::floor((r - l)/2);
            if (target < nums[m])
                r = m - 1;
            else if (target > nums[m])
                l = m + 1;
            else
                return m;
        }
        return -1 ;
    }
    void print(int out) {
        std::cout << out << "\n";
    }

    void example() {
        std::vector<int> in = { -1,0,3,5,9,12 }; int target = 9;
        print(search(in, target));
    }
};
//74. Search a 2D Matrix
namespace Searcha2DMatrix {
    bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
        const int ROWS = matrix.size();
        const int COLS = matrix[0].size();

        int top = 0;
        int bot = ROWS -1 ;
        int midRow;
        while (top <= bot)
        {
            midRow = top + (bot - top)/2;
            if ((target == matrix[midRow][0])||(target == matrix[midRow][COLS - 1]))
                return true;
            if ((target > matrix[midRow][0]) && (target < matrix[midRow][COLS - 1]))
                break;
            if(target > matrix[midRow][COLS - 1])
            {
                top = midRow + 1;
            }
            else
                bot = midRow - 1;
        
        } 
        int l = 0;
        int r = COLS - 1;
        int m;
        while (l <= r)
        {
            m = l + (r - l)/2;
            if (target < matrix[midRow][m])
            {
                r = m - 1;
            }
            else if (target > matrix[midRow][m])
            {
                l = m + 1;
            }
            else 
            {  
                return true;
            }
        } 
        return false;
    }
    void print(bool out) {
        std::cout << (out?"True":"False") << "\n";
    }

    void example() {
        std::vector<std::vector<int>> in = { {1,3,5,7},{10,11,16,20},{23,30,34,60} }; int target = 3;
        print(searchMatrix(in, target));
    }
};
//875. Koko Eating Bananas
namespace KokoEatingBananas {
    inline int maxpile(std::vector<int>& piles)
    {
            int max = piles[0];
            for (int pile : piles)
            {
                if (pile > max)
                    max = pile;
            }
            return max;
    };
    int minEatingSpeed(std::vector<int>& piles, int h) {
        int n = piles.size();

        int low = 1;
        int high = 0;
        for (int i = 0; i < n; i++) {
            high = std::max(high, piles[i]);
        }

        int result = high;

        while (low <= high) {
            int k = low + (high - low) / 2;
            long int hours = 0;
            for (int i = 0; i < n; i++) {
                hours += std::ceil((double)piles[i] / k);
            }
            if (hours <= h) {
                result = std::min(result, k);
                high = k - 1;
            }
            else {
                low = k + 1;
            }
        }

        return result;
    }
    void print(int out) {
        std::cout << out << "\n";
    }

    void example() {
        std::vector<int> in = { 30,11,23,4,20 }; int h = 6;
        print(minEatingSpeed(in, h));
    }

 };

int main(){
    GroupAnagrams::example();
    TopKFrequent::example();
    ProductExceptSelf::example();
    SearchInRotatedSortedArray::example();
    Searcha2DMatrix::example();
    BinarySpace::example();
    KokoEatingBananas::example();
    return 0;
}