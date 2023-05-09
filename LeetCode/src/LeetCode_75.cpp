#include <iostream> 
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <math.h>
#include <string>
#include <stack>
#include <memory>
#include <sstream>
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
//124. Binary Tree Maximum Path Sum
    struct TreeNode {
        int val;
        TreeNode* left;
        TreeNode* right;
        TreeNode(): val(0), left(nullptr), right(nullptr){}
        TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
        TreeNode(int x, TreeNode* left, TreeNode* right):val(x), left(left), right(right) {}
    };
namespace BinaryTreeMaximumPathSum {
    std::pair<int,int> dfs(TreeNode* node)  
    {
        if ((node->left->left == nullptr) && (node->left->right == nullptr)
            && (node->right->left == nullptr) && (node->right->right == nullptr))
            return std::make_pair(node->left->val + node->right->val + node->val, 
                node->val + (node->left->val > node->right->val ? node->left->val : node->right->val));
        auto left = dfs(node->left);
        auto right = dfs(node->right);
        int childPath = (left.first > right.first ? left.first : right.first);
        int newPath = left.second + node->val + right.second;
        return std::make_pair(std::max(childPath, newPath),
            node->val + (left.second > right.second ? left.second : right.second));

    }
    int maxPathSum(TreeNode* root) {
        auto res = dfs(root);
        return std::max(res.first, res.second);
    }
    void print(int out) {
        std::cout << out << "\n";
    }

    void example() {
        std::vector<int> in = { -10,9,20,0,0,15,7 };
        TreeNode node7 = TreeNode(7);
        TreeNode node6 = TreeNode(15);
        TreeNode node5 = TreeNode();
        TreeNode node4 = TreeNode();
        TreeNode node3 = TreeNode(20, &node6, &node7);
        TreeNode node2 = TreeNode(9, &node4, &node5);
        TreeNode root = TreeNode(-10, &node2, &node3);
        print(maxPathSum(&root));
    }
    
}
//297. Serialize and Deserialize Binary Tree
namespace Codec {

        void encode(TreeNode* root, std::ostringstream& out) {
            if (root == NULL) {
                out << "N ";
                return;
            }

            out << root->val << " ";

            encode(root->left, out);
            encode(root->right, out);
        }

        TreeNode* decode(std::istringstream& in) {
            std::string value = "";
            in >> value;

            if (value == "N") {
                return NULL;
            }

            TreeNode* root = new TreeNode(stoi(value));

            root->left = decode(in);
            root->right = decode(in);

            return root;
        }

        // Encodes a tree to a single string.
        std::string serialize(TreeNode* root) {
            std::ostringstream out;
            encode(root, out);
            return out.str();
        }

        // Decodes your encoded data to tree.
        TreeNode* deserialize(std::string data) {
            std::istringstream in(data);
            return decode(in);
        }
    void print(std::vector<int> to_serialize, std::string serialized) {
        std::cout << "_____________________________________________\n";
        for (auto v : to_serialize)
        {
            std::cout << v << " ";
        }
        std::cout << serialized << "\n";
    }
    void printDeserialize(TreeNode* root, std::string str)
    {
        std::stack<TreeNode*> stack;
        stack.push(root);
        while (!stack.empty())
        {
            TreeNode* node = stack.top();
            stack.pop();
            std::cout << node->val<< " ";
            if (!node->left)
                stack.push(node->left);
            if (!node->right)
                stack.push(node->right);
        }
        std::cout << str << "\n";
    }

    void example() {
        TreeNode node7 = TreeNode(7);
        TreeNode node6 = TreeNode(15);
        TreeNode node5 = TreeNode();
        TreeNode node4 = TreeNode();
        TreeNode node3 = TreeNode(20, &node6, &node7);
        TreeNode node2 = TreeNode(9, &node4, &node5);
        TreeNode root = TreeNode(-10, &node2, &node3);
        std::vector<int> in = { -10,9,20,0,0,15,7 };
        print(in, serialize(&root));
        printDeserialize(deserialize(serialize(&root)), (serialize(&root)));

    }
}
//212. Word Search II
//namespace WordSearch {
//    class TrieNode {
//        std::string parent;
//        std::
//    };
//}
//235. Lowest Common Ancestor of a Binary Search Tree
namespace LCAinBST {
    //Best Solution
    TreeNode* lowestCommonAncestor2(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (p->val < root->val && q->val < root->val) {
            return lowestCommonAncestor2(root->left, p, q);
        }
        else if (p->val > root->val && q->val > root->val) {
            return lowestCommonAncestor2(root->right, p, q);
        }
        else {
            return root;
        }
    }
    //MySolution
    TreeNode* binarySearch(TreeNode* parent, int val, std::vector<TreeNode*>& path) {
        path.push_back(parent);
        if (val == parent->val) return parent;
        if (val < parent->val)
            binarySearch(parent->left, val, path);
        else if (val > parent->val)
            binarySearch(parent->right, val, path);
        else
            return nullptr;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        std::vector<TreeNode*> pathp;
        binarySearch(root, p->val, pathp);
        std::vector<TreeNode*> pathq;
        binarySearch(root, q->val, pathq);
        int pathLength = std::min(pathq.size(), pathp.size());
        TreeNode* common = root;
        for (int i = 0; i < pathLength; i++) {
            if (pathp[i] == pathq[i]) common = pathp[i];
        }
        return common;
    }
    void print(TreeNode* out) {
        std::cout << out->val << "\n";
    }

    void example() {
        std::vector<int> in = { 2,1 };
        int p = 2; 
        int q = 1;
        std::vector<TreeNode*> inNodes;
        inNodes.resize(in.size());
        int pIdx, qIdx;
        for (int i = 0; i < in.size(); i++)
        {
            inNodes[i] = new TreeNode(in[i]);
            if (inNodes[i]->val == p)
                pIdx = i;
            if (inNodes[i]->val == q)
                qIdx = i;
        }
        for (int i = 0; i < (int)(in.size()/2); i++)
        {
            if ((2 * i + 1) < in.size())
                inNodes[i]->left = inNodes[2 * i + 1];
            if ((2 * i + 2) < in.size())
                inNodes[i]->right = inNodes[2 * i + 2];
        }
        print(lowestCommonAncestor(inNodes[0], inNodes[pIdx], inNodes[qIdx]));
        print(lowestCommonAncestor2(inNodes[0], inNodes[pIdx], inNodes[qIdx]));
    }
}
//102. Binary Tree Level Order Traversal
namespace BinaryTreeLevelOrderTraversal {
    std::vector<std::vector<int>> levelOrder(TreeNode* root) {
        std::vector<std::vector<int>> result;

        if (root == nullptr) return result;
        std::queue<TreeNode*> q;
        q.push(root);
        while (!q.empty())
        {
            int n = (int)q.size();
            std::vector<int> currentLevel;
            for (int i = 0; i < n; i++) {
                TreeNode* node = q.front();
                q.pop();

                currentLevel.push_back(node->val);

                if (node->left != nullptr)
                    q.push(node->left);
                if (node->right != nullptr)
                    q.push(node->right);
            }
            result.push_back(currentLevel);
        }
        return result;
    }
    void print(const std::vector<std::vector<int>>& out) {
        std::cout << "[";
        for (int i = 0; i < out.size(); i++)
        {
            std::cout << "[";
            for (int j = 0; j < out[i].size(); j++)
            {
                std::cout << out[i][j] << " ";
            }
            std::cout << "]";
        }
        std::cout << "]\n";
    }

    void example() {
        std::vector<int> in = { 3,9,20,-1,-1,15,7 };
        std::vector<TreeNode*> inNodes(in.size(), nullptr);
        for (int i = 0; i < in.size(); i++)
            if (in[i] != -1)
                inNodes[i] = new TreeNode(in[i]);
        for (int i = 0; i < (int)(in.size() / 2); i++)
        {
            if ((2 * i + 1) < in.size())
                inNodes[i]->left = inNodes[2 * i + 1];
            if ((2 * i + 2) < in.size())
                inNodes[i]->right = inNodes[2 * i + 2];
        }
        print(levelOrder(inNodes[0]));
    }
}
//199. Binary Tree Right Side View
namespace BinaryTreeRightSideView {
    //return the branch on the right side, if that branch is shorter than other branches of the tree, it is supposed to return the
    //node most to the right from other branches. 
    std::vector<int> rightSideView_Wrong(TreeNode* root) {
        std::vector<int> result;
        if (root == nullptr) return result;
        result.push_back(root->val);
        TreeNode* node = root;
        while (node->right || node->left)
        {
            if (node->right != nullptr)
            {
                result.push_back(node->right->val);
                node = node->right;
            }
            else
            {
                result.push_back(node->left->val);
                node = node->left;
            }
        }
        return result;
    }
    std::vector<int> rightSideView(TreeNode* root) {
        std::vector<int> result;
        if (root == nullptr) return result;
        
        std::queue<TreeNode*> q;
        q.push(root);

        while (!q.empty())
        {
            int n = (int)q.size();
            for (int i = 0; i < n; i++)
            {
                TreeNode* node = q.front();
                q.pop();

                if (node->right != nullptr)
                    q.push(node->right);
                if (node->left != nullptr)
                    q.push(node->left);

                if (i == 0)
                    result.push_back(node->val);
            }
        }
        return result;
    }
    void print(const std::vector<int>& out) {
        std::cout << "[";
        for (int j = 0; j < out.size(); j++)
        {
            std::cout << out[j] << " ";
        }
        std::cout << "]";
    }

    void example() {
        std::vector<int> in = {1,2,3,4};
        std::vector<TreeNode*> inNodes(in.size(), nullptr);
        for (int i = 0; i < in.size(); i++)
            if (in[i] != -1)
                inNodes[i] = new TreeNode(in[i]);
        for (int i = 0; i < (int)(in.size() / 2); i++)
        {
            if ((2 * i + 1) < in.size())
                inNodes[i]->left = inNodes[2 * i + 1];
            if ((2 * i + 2) < in.size())
                inNodes[i]->right = inNodes[2 * i + 2];
        }
        print(rightSideView(inNodes[0]));
    }
}
//1448. Count Good Nodes in Binary Tree
namespace BinaryTreeCountGoodNodes {
    void dfs(TreeNode* node, int max, int& count) {
        if (node == nullptr) return;
        if (node->val >= max) 
        {
            count++;
            max = node->val;
        }
        dfs(node->left, max, count);
        dfs(node->right, max, count);
    }

    int goodNodes(TreeNode* root)
    {
        int count = 0;
        dfs(root, root->val, count);
        return count;
    }
    void print(int out) {
        std::cout << out << "\n";
    }

    void example() {
        std::vector<int> in = { 3,1,4,3,-1,1,5 };
        std::vector<TreeNode*> inNodes(in.size(), nullptr);
        for (int i = 0; i < in.size(); i++)
            if (in[i] != -1)
                inNodes[i] = new TreeNode(in[i]);
        for (int i = 0; i < (int)(inNodes.size() / 2); i++)
        {
            if (inNodes[i] != nullptr)
            {
                if ((2 * i + 1) < in.size())
                    inNodes[i]->left = inNodes[2 * i + 1];
                if ((2 * i + 2) < in.size())
                    inNodes[i]->right = inNodes[2 * i + 2];
            }
        }
        print(goodNodes(inNodes[0]));
    }
}
//98. Validate Binary Search Tree
namespace ValidateBST {
    //Although it fits the definition of the bst given by the leetcode challenge, it doesn't fit the definition of a BST,
    //where for example the left node should be smaller than its parent BUT ALSO PARENT NODE OF ITS PARENT
    bool isValidBST_Wrong(TreeNode* root) {
        if (root == nullptr) return true;
        if (((root->left == nullptr) || (root->left->val < root->val))
            && ((root->right == nullptr) || (root->right->val > root->val)))
            return (isValidBST_Wrong(root->left)
                && isValidBST_Wrong(root->right));
        return false;
    }
    bool foo(TreeNode* node, long leftBound, long rightBound) {
        if (node == nullptr) return true;
        if ((node->val < rightBound) && (node->val > leftBound))
            return foo(node->left, leftBound, node->val) && foo(node->right, node->val, rightBound);
        return false;
    }
    bool isValidBST(TreeNode* root) {
        if (root == nullptr) return true;
        return foo(root,0x80000000, 0x7FFFFFFF);

    }
    void print(bool out) {
        std::cout << (out?"true":"false") << "\n";
    }
    void example() {
        std::vector<int> in = { 98,-57,-1,-1,58,-1,-1,-1,-1,31 };
        std::vector<TreeNode*> inNodes(in.size(), nullptr);
        for (int i = 0; i < in.size(); i++)
            if (in[i] != -1)
                inNodes[i] = new TreeNode(in[i]);
        for (int i = 0; i < (int)(inNodes.size() / 2); i++)
        {
            if (inNodes[i] != nullptr)
            {
                if ((2 * i + 1) < in.size())
                    inNodes[i]->left = inNodes[2 * i + 1];
                if ((2 * i + 2) < in.size())
                    inNodes[i]->right = inNodes[2 * i + 2];
            }
        }
        print(isValidBST(inNodes[0]));
    }
}
//230. Kth Smallest Element in a BST
namespace BSTKthSmallestElement {
    void checkLeft(TreeNode* node, int& k, int& val) {
       if (!node) return;
       checkLeft(node->left, k, val);
       --k;
       if (k == 0) {
           val = node->val;
           return;
       }
       checkLeft(node->right, k, val);

    }
    int kthSmallest(TreeNode* root, int k) {
        int val = 0;
        checkLeft(root, k, val);
        return val;
    }
    void print(int out) {
        std::cout << out << "\n";
    }
    void example() {
        std::vector<int> in = { 5,3,6,2,4,-1,-1,1 };
        std::vector<TreeNode*> inNodes(in.size(), nullptr);
        for (int i = 0; i < in.size(); i++)
            if (in[i] != -1)
                inNodes[i] = new TreeNode(in[i]);
        for (int i = 0; i < (int)(inNodes.size() / 2); i++)
        {
            if (inNodes[i] != nullptr)
            {
                if ((2 * i + 1) < in.size())
                    inNodes[i]->left = inNodes[2 * i + 1];
                if ((2 * i + 2) < in.size())
                    inNodes[i]->right = inNodes[2 * i + 2];
            }
        }
        print(kthSmallest(inNodes[0],3));
    }
}
//78. Subsets
namespace BacktrackingSubsets {

    void dfs(std::vector<std::vector<int>>& result, int start, std::vector<int>& l, std::vector<int>& nums)
    {
        result.push_back(l);
        for (int i = start; i < nums.size(); i++) {
            l.push_back(nums[i]);
            dfs(result, i + 1, l, nums);
            l.pop_back();
        }
    }
    std::vector<std::vector<int>> subsets(std::vector<int>& nums) {
        std::vector<std::vector<int>> result;
        std::vector<int> l;
        dfs(result, 0, l, nums);
        return result;
    }
    void print(const std::vector<std::vector<int>>& out) {
        std::cout << "[";
        for (int i = 0; i < out.size(); i++)
        {
            std::cout << "[";
            for (int j = 0; j < out[i].size(); j++)
            {
                std::cout << out[i][j] << " ";
            }
            std::cout << "]";
        }
        std::cout << "]\n";
    }

    void example() {
        std::vector<int> in = { 1,2,3 };
        print(subsets(in));
    }
}
//39. Combination Sum
namespace BacktrackingCombinationSum {
    void dfs(std::vector<int>& candidates, int target, int sum, int start, std::vector<int>& l, std::vector<std::vector<int>>& result)
    {
        if (sum > target) return;
        if (sum == target) {
            result.push_back(l);
            return;
        }
        for (int i = start; i < candidates.size(); i++) {
            l.push_back(candidates[i]);
            dfs(candidates, target, sum + candidates[i], i, l, result);
            l.pop_back();
        }
    }
    std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target)
    {
        std::sort(candidates.begin(), candidates.end());
        std::vector<int> l;
        std::vector<std::vector<int>> result;
        dfs(candidates, target, 0, 0, l, result);
        return result;
    }
    void print(const std::vector<std::vector<int>>& out) {
        std::cout << "[";
        for (int i = 0; i < out.size(); i++)
        {
            std::cout << "[";
            for (int j = 0; j < out[i].size(); j++)
            {
                std::cout << out[i][j] << " ";
            }
            std::cout << "]";
        }
        std::cout << "]\n";
    }
    void example() {
        std::vector<int> in = { 2,3,6,7 };
        int target = 7;
        print(combinationSum(in, target));
    }
}
//46. Permutations
namespace BacktrackingPermutations {
    
    void dfs(std::vector<std::vector<int>>& result, int start, std::vector<int>& nums) {
        if (start == nums.size()) {
            result.push_back(nums);
            return;
        }

        for (int i = start; i < nums.size(); i++) {
            std::swap(nums[i], nums[start]);
            dfs(result, start + 1, nums);
            std::swap(nums[i], nums[start]);
        }
    }

    std::vector<std::vector<int>> permute(std::vector<int>& nums) {
        std::vector<std::vector<int>> result;
        dfs(result, 0, nums);
        return result;
    }
    
    void print(const std::vector<std::vector<int>>& out) {
        std::cout << "[";
        for (int i = 0; i < out.size(); i++)
        {
            std::cout << "[";
            for (int j = 0; j < out[i].size(); j++)
            {
                std::cout << out[i][j] << " ";
            }
            std::cout << "]";
        }
        std::cout << "]\n";
    }

    void example() {
        std::vector<int> in = { 1 };
        print(permute(in));
    }
}
//90. Subsets II
namespace BacktrackingSubsets2 {
    void dfs(std::vector<std::vector<int>>& result, int start, std::vector<int>& curr, std::vector<int>& nums) {
            result.push_back(curr);
        for (int i = start; i < nums.size(); i++) {
            if (i > start && nums[i] == nums[i - 1]) {
                continue;
            }
            curr.push_back(nums[i]);
            dfs(result, i + 1, curr, nums);
            curr.pop_back();
        }
    }

    std::vector<std::vector<int>> subsetsWithDup(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());

        std::vector<std::vector<int>> result;
        std::vector<int> curr;
        
        dfs(result, 0, curr, nums);
        return result;
    }
    void print(const std::vector<std::vector<int>>& out) {
        std::cout << "[";
        for (int i = 0; i < out.size(); i++)
        {
            std::cout << "[";
            for (int j = 0; j < out[i].size(); j++)
            {
                std::cout << out[i][j] << " ";
            }
            std::cout << "]";
        }
        std::cout << "]\n";
    }

    void example() {
        std::vector<int> in = { 1,2,2 };
        print(subsetsWithDup(in));
    }
}
//40. Combination Sum II
namespace BacktrackingCombinationSum2 {
    void dfs(std::vector<std::vector<int>>& result, int start, int target, std::vector<int>& curr ,std::vector<int>& candidates) {
        if (target < 0)
            return;
        if (target == 0)
        {
            result.push_back(curr);
            return;
        }
        for (int i = start; i < candidates.size(); i++)
        {
            if ((i > start) && (candidates[i] == candidates[i - 1]))
                continue;
            curr.push_back(candidates[i]);
            dfs(result, i + 1, target - candidates[i], curr, candidates);
            curr.pop_back();
        }
    }
    std::vector<std::vector<int>> combinationSum2(std::vector<int>& candidates, int target) {
        std::sort(candidates.begin(), candidates.end());

        std::vector<std::vector<int>> result;
        std::vector<int> curr;

        dfs(result, 0, target, curr, candidates);
        return result;
    }
    void print(const std::vector<std::vector<int>>& out) {
        std::cout << "[";
        for (int i = 0; i < out.size(); i++)
        {
            std::cout << "[";
            for (int j = 0; j < out[i].size(); j++)
            {
                std::cout << out[i][j] << " ";
            }
            std::cout << "]";
        }
        std::cout << "]\n";
    }
    void example() {
        std::vector<int> in = { 10,1,2,7,6,1,5 };
        int target = 8;
        print(combinationSum2(in, target));
    }
}
//79. Word Search
namespace BacktrackingWordSearch {
    //(BETTER)SOLUTION
    bool dfs(std::vector<std::vector<char>>& board, std::string word,
        int index, int i, int j, int m, int n) {

        if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] != word[index]) {
            return false;
        }
        if (index == word.size() - 1) {
            return true;
        }

        board[i][j] = '#';

        if (dfs(board, word, index + 1, i - 1, j, m, n)
            || dfs(board, word, index + 1, i + 1, j, m, n)
            || dfs(board, word, index + 1, i, j - 1, m, n)
            || dfs(board, word, index + 1, i, j + 1, m, n)) {
            return true;
        }

        board[i][j] = word[index];
        return false;
    }
    bool exist2(std::vector<std::vector<char>>& board, std::string word) {
        int m = board.size();
        int n = board[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0]) {
                    if (dfs(board, word, 0, i, j, m, n)) {
                        return true;
                    }
                }
            }
        }

        return false;
    }
    //FIRST SOLUTION
    void helper(std::vector<std::vector<char>>& board, int rowIdx, int colIdx, std::string& word, int letterIdx, bool& result, std::vector<std::vector<char>>& markedTiles){// dir direction) {
        if (letterIdx == word.length())
        {
            result = true;
            return;
        }
        if (board[rowIdx][colIdx] == word[letterIdx])
        {
            bool didItEnd = true;
            if ((rowIdx < board.size() - 1) && (markedTiles[rowIdx+1][colIdx] =='_'))
            {
                didItEnd = false;
                markedTiles[rowIdx + 1][colIdx] = 'm';
                helper(board, rowIdx + 1, colIdx, word, letterIdx + 1, result, markedTiles);
                markedTiles[rowIdx + 1][colIdx] = '_';
            }
            if ((colIdx < board[0].size() - 1) && (markedTiles[rowIdx][colIdx+1] == '_'))
            {
                didItEnd = false;
                markedTiles[rowIdx][colIdx + 1] = 'm';
                helper(board, rowIdx, colIdx + 1, word, letterIdx + 1, result, markedTiles);
                markedTiles[rowIdx][colIdx + 1] = '_';
            }
            if ((colIdx > 0) && (markedTiles[rowIdx][colIdx-1] == '_'))
            {
                didItEnd = false;
                markedTiles[rowIdx][colIdx - 1] = 'm';
                helper(board, rowIdx, colIdx - 1, word, letterIdx + 1, result, markedTiles);
                markedTiles[rowIdx][colIdx - 1] = '_';
            }
            if ((rowIdx > 0) && (markedTiles[rowIdx- 1][colIdx] == '_'))
            {
                didItEnd = false;
                markedTiles[rowIdx - 1][colIdx] = 'm';
                helper(board, rowIdx - 1, colIdx, word, letterIdx + 1, result, markedTiles);
                markedTiles[rowIdx - 1][colIdx] = '_';
            }
            if (didItEnd && (letterIdx + 1 == word.length()))
                result = true;
        }
    }

    bool exist(std::vector<std::vector<char>>& board, std::string word) {
        bool result = false;
        int letterIdx = 0;
        for (int i = 0; (i < board.size()); i++) {
            for (int j = 0; (j < board[0].size()); j++) {
                if (word[letterIdx] == board[i][j])
                {
                    std::vector<std::vector<char>> markedTiles(board.size(), std::vector<char>(board[0].size(), '_'));
                    markedTiles[i][j] = 'm';
                    helper(board, i, j, word, 0, result, markedTiles);
                    if (result) return true;
                    if ((board.size() == 1) && (board[0].size() == 1) && (word.length() == 1)) return true;
                }

            }
        }
        return false;
    }
    void print(bool out) {
        std::cout << (out ? "true" : "false") << "\n";
    }
    void example() {
        std::vector<std::vector<char>> in = { {'a','a','a','a'}, {'a','a','a','a'} ,{'a','a','a','a'} };
        std::string word = "aaaaaaaaaaaaa";
        print(exist(in, word));
        print(exist2(in, word));
    }
}
int main(){
    /*GroupAnagrams::example();
    TopKFrequent::example();
    ProductExceptSelf::example();
    SearchInRotatedSortedArray::example();
    Searcha2DMatrix::example();
    BinarySpace::example();
    KokoEatingBananas::example();
    BinaryTreeMaximumPathSum::example();
    Codec::example();
    LCAinBST::example();
    BinaryTreeLevelOrderTraversal::example();
    BinaryTreeRightSideView::example();
    BinaryTreeCountGoodNodes::example();
    ValidateBST::example();
    BSTKthSmallestElement::example();*/
    //BacktrackingSubsets::example();
    /*BacktrackingCombinationSum::example();
    BacktrackingPermutations::example();*/
    //BacktrackingSubsets2::example();
    //BacktrackingCombinationSum2::example();
    BacktrackingWordSearch::example();
}