### Data structure

* Priority_queue

```cpp
auto compare = [](const int i, const int j) {return i > j;};
std::priority_queue <int, vector<int>, decltype(compare)> pq(compare);
pq.push()
pq.empty()
pq.pop()
pq.top()
```

* stack

```cpp
std::stack<int> s;
s.push();
s.top();
s.size();
s.empty();
s.pop();
```

* queue

```cpp
std::queue<int> q;
q.size();
q.push();
q.front();
q.pop();
```

### Classic Algorithm

* Binary search

```cpp
// single index search
int binary_search(vector<int>& nums, int target) {
    int i = 0, j = nums.size() - 1;
    while(i <= j) { // search range is [i, j], only end if [k + 1, k]
        int mid = i + (j - i) / 2;
        if(nums[mid] == target) {
            return mid;
        }else if(nums[mid] > target) {
            j = mid - 1;
        }else if(nums[mid] < target) {
            i = mid + 1;
        }
    }

    return -1;
}

// case 1:
// for left_bound([2, 2, 5, 6], 1), it will return 0, 
// meaning there is 0 number in nums that is smaller than 1
//
// case 2:
// for left_bound([2, 2, 5, 6], 8), it will return 4,
// meaning there is 4 number in nums that is smaller than 8
int left_bound(vector<int>& nums, int target) {
    int i = 0, j = nums.size() - 1;
    while(i <= j) { 
        int mid = i + (j - i) / 2;
        if(nums[mid] == target) {
            j = mid - 1;
        }else if(nums[mid] > target) {
            j = mid - 1;
        }else if(nums[mid] < target) {
            i = mid + 1;
        }
    }

    if(i == nums.size() || nums[i] != target) return -1;
    // case 2              case 1

    return i;
}

int right_bound(vector<int>& nums, int target) {
    int i = 0, j = nums.size() - 1;
    while(i <= j) { 
        int mid = i + (j - i) / 2;
        if(nums[mid] == target) {
            i = mid + 1;
        }else if(nums[mid] > target) {
            j = mid - 1;
        }else if(nums[mid] < target) {
            i = mid + 1;
        }
    }

    if(j < 0 || nums[j] != target) return -1;

    return j;
}
```

* quick sort

```cpp
void quickSort(vector<int>& nums) {
    quickSort_helper(nums, 0, nums.size() - 1);
}

void quickSort_helper(vector<int>& nums, int start, int end) {
    // if only one element, no need to do sort
    if(start >= end) return;

    // random choose piviot to avoid worst case
    int piviot = rand() % (end - start) + start;
    // place the piviot into correct spot
    int position = partition(nums, start, end, piviot);

    // gradually sort the left and right
    quickSort(nums, start, position - 1);
    quickSort(nums, position + 1, end);
}

int partition(vector<int>&nums, int start, int end, int piviot) {
    int target = nums[piviot];
    swap(nums, end, piviot);

    int i = start;
    int j = end - 1;

    while(true) {
        // i cannot exceed the limit
        while(nums[i] <= target && i < end) {
            i++;
        }

        // j cannot exceed the i
        while(nums[j] > target && j > i) {
            j--;
        }

        if(i >= j) break;

        swap(nums, i, j);
    }

    // remember to check if i is already out of the bound
    // then put the piviot into the right spot
    if(i < end) swap(nums, i, end);

    // return piviot's index
    return i;
}

void swap(vector<int>&nums, int i, int j) {
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
}
```

* Dynamic Programming
  * Backpack problem
    * We have a backpack that has volumn $N$, and we have a bunch of items each has its own volumn $W_i$ and value $V_i$, we want to maximize the total value of the items that can be put into the bag.

    * Define a $dp[i][j]$ means with $i$ items already seen and $j$ volumn limit, $dp[i][j]$ is the maximum value we can reach

    * Updates Rule: 
        $$dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - W_j] + V_j)$$ 
        Meaning we can either put the $j$th item in the bag or discard it

    * Advance Optimazation: 
        $dp[i][j]$ only relate to $dp[i - 1][*]$, so we can compress the 2d array into 1d array 
        
        $$dp[j] = max(dp[j], dp[j - W_j] + V_j)$$
        
        It is worth noting that the $dp[j - W_j]$ is actually the $dp[i - 1][j - W_j]$ item, so once we update $dp[j]$ we must keep the value of last round's $dp[j - W_j]$ intact, meaning we have to **reversely update the whole array!!!**

    ```cpp
    int knapsack(int N, vector<int>& weights, vector<int>& values) {
        int size = weights.size();
        // Have to include the empty bag case for base case
        vector<int> dp(N + 1, 0); 

        for(int i = 0; i < size; i++) {
            for(int int j = N; j > 0; j++) {
                dp[j] = max(dp[j], dp[j - weights[i]] + values[i]);
            }
        }
        
        return dp[N];
    }
    ```

    * If we are dealing with the whole backpack problem([Coin change](https://leetcode.com/problems/coin-change-2/description/)), meaning there are infinite items that we can pack into the bag, then our update rule is $$dp[i][j] = max(dp[i][j - W[i]], dp[i - 1][j])$$ meaning either we completely discard this item and never use it or we use it for once that see if we can still use it. In this way, we cannot do the reverse update rule for optimization because in $dp[j] = max(dp[j - W[i]], dp[j])$, $dp[j - W[i]]$ is the value in $dp[i]$'s round, so we should do **normal sequence update**

    * If we care about the certain order of items that get packed into the bag, we should change the order of two iterations, meaning we should **first iterate through backpack's volumn then iterate through the items**.

* add two numbers
    * two numbers $x$ and $y$ in their string representation, how to add them digit by digit

    ```cpp
    string add_number(string x, string y) {
        int size1 = x.size(), size2 = y.size();
        int i = size1 - 1, j = size2, carry = 0;
        string result = "";
        while(i >= 0 || j >= 0 || carry >= 0) {
            if(i >= 0) {
                carry += (int)(x[i] - '0');
                i--;
            }

            if(j >= 0) {
                carry += (int)(y[j] - '0');
                j--;
            }

            result = (char)((carry % 10) + '0') + result;
            carry /= 10;
        }

        return result;

    }
    ```

* BFS template

    ```cpp
    std::queue<T> q;
    unordered_set<T> visited;
    int step = 0;

    q.push(start_state);

    // while there are still search spaces
    while(!q.empty()) {
        int level = q.size();
        step++;

        // this level's size
        while(level) {
            auto temp_step = q.front();
            q.pop();

            // if we actually meet the result state
            if(temp_step == final_step) return step;

            // find all valid next states from this pop state
            for(auto& next_step : find_next_step(temp_step)) {
                // if we already meet this state, then we skip it
                if(visited.count(next_step)) continue;
                // update the queue and the visited
                q.push(next_step);
                visited.insert(next_step);
            }

            level--
        }
    }

    // out of the searching loop, meaning we does not find anything
    return -1;
    ```

* add number into a fixed length vector by its relative priority

    ```cpp
    // original we may add number into a dynamically growed vector
    std::vector<int> result;
    for(auto& each_ele : random_arr) {
        int num = each_ele[0], priority = each_ele[1];
        result.insert(priority, num);
    }

    // instead we can do this
    std::vector<int> result(random_arr.size(), 0);
    int count = 0; // counter for how many number we have already input

    for(auto& each_ele : random_arr) {
        int num = each_ele[0], priority = each_ele[1];
        for(int i = count; i > priority; i--) { 
            // move all number that is larger than priority to the next position
            // to save for space for current input number
            result[i] = result[i - 1]
        }

        // don't forget to increment the counter
        count++;
        result[priority] = num;
    }
    ```

* backtrack template

    ```cpp
    void backtrack(vector<vector<int>> result, vector<int> single_result, int current, int end) {
        if(current == end) {
            // a successful result
            vector<int> temp(single_result);
            result.push_back(temp)
        }else if(edge condition) {
            // reach out of bounds or other end condition 
            return;
        }else{
            for(auto& valid_choice : choice_space) {
                // add choice
                single_result.push_back(valid_choice);

                // go to next level
                backtrack(result, single_result, current + 1, end);
                
                // when go back to this line
                // meaning we have exhaust all choices starting with this valid_choice
                // so we undo this valid_choice
                single_result.pop_back()
            }
        }
    }
    ```

    * sometimes we may face some duplicates in the search space and the answer should contain all unique choices without duplicates, we can handle it by adding


* Prefix Sum
    * Problem Setting: Find a number of continuous subarrays that sum to target.
    ```cpp
    int SumPath(vector<int> nums, int target) {
        unordered_map<int, int> record;
        int cur_sum = 0;
        int result = 0;

        for(auto& ele : nums) {
            cur_sum += ele;

            // if we can reach the target by adding from head to current position
            if(cur_sum == target) {
                result ++;
            }

            // check if the target can be sum from previous point to current position
            result += record[cur_sum - target];

            record[cur_sum] += 1;
        }

        return result;
    }
    ```

    * if the number is dynamically changing, we should use Binary Index Tree
    ```cpp
    class Fenwick_Tree {
    public:
        Fenwick_Tree(int size) {
            _sum = vector<int>(size + 1, 0);
        }
        
        
        void Update(int i, int val) {
            while(i < _sum.size()) {
                _sum[i] += val;
                i += lower_bit(i);
            }
        }
        
        int Query(int i) {
            int result = 0;
            while(i > 0) {
                result += _sum[i];
                i -= lower_bit(i);
            }
            
            return result;
        }
        
    private:
        int lower_bit(int num) {
            return num & (-num);
        }
        
        vector<int> _sum;
    };
    ```

* Binary Tree
    * do inorder traverse by iteration
        ```cpp
        void inorder(TreeNode* root) {
            if(!root) return;

            stack<TreeNode*> s;
            TreeNode* cur = root;

            while(cur || !s.empty()) {
                while(cur) {
                    s.push(cur);
                    cur = cur->left;
                }

                auto temp = s.top();
                s.pop();

                cur = node->right;
            }
        }
        ```
    
    * Lowest Common Ancestor
    ```cpp
    TreeNode *ans;
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        ans = nullptr;
        traverse(root, p, q);
        return ans;
    }
    
    bool traverse(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return false;
        
        int meet_target_node_left = traverse(root->left, p, q);
        int meet_target_node_right = traverse(root->right, p, q);
        int meet_target_node_self = (root == p || root == q);
        
        // if we reach both of the target node
        // we know it is a LCA
        if(meet_target_node_left + meet_target_node_right + meet_target_node_self >= 2) {
            ans = root;
        }
        
        // Note !!!
        // we only return if one target node has been detected from this root
        return (meet_target_node_left + meet_target_node_right + meet_target_node_self > 0);
        
    }
    ```

* Fast forward pow $x^n$
    ```cpp
    class Solution {
    public:
        // Time: O(logn), Space: O(logn)
        double myPow(double x, int n) {
            long long N = n; // prevent overflow
            if(n < 0) {
                N = -N;
                x = 1/x;
            }
            
            return power_helper(x, n);
        }
        
        // x^(2n) = x^n * x^n
        double power_helper(double x, long long n) {
            if(n == 0) return 1;
            
            double half = power_helper(x, n/2);
            
            if(n % 2 == 0) {
                return half * half;
            }else{
                return half * half * x;
            }
        }
    };
    ```

* check number of valid palidroms substrings in a string
    ```cpp
    class Solution {
    public:
        int count;
        
        // Time: O(n^2), Space: O(1)
        int countSubstrings(string s) {
            count = 0;
            
            // check all valid palindrome start from s[i]
            for(int i = 0; i < s.size(); i++) {
                extendSubstrings(s, i, i);
                extendSubstrings(s, i, i + 1);
            }
            
            return count;
        }
        
        void extendSubstrings(string& s, int start, int end) {
            while(start >= 0 && end < s.size() && s[start] == s[end]) {
                start--;
                end++;
                count++;
            }
        
        }
    };
    ```

* move zero to the end the array while keeping the original order of the array
    ```cpp
    class Solution {
    public:
        void moveZeroes(vector<int>& nums) {
            int n = nums.size();
            if(n <= 1) return; 
            
            int offset = 0;
            for(int i = 0; i < n; i++) {
                if(nums[i]) {
                    if(i != offset) {
                        swap(nums, i, offset);
                    }
                    
                    offset++;
                }
            }
        }
        
        void swap(vector<int>& nums, int i, int j) {
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
        }
    };
    ```

* Given two integers $n$ and $k$, construct a list answer that contains $n$ different positive integers ranging from $1$ to $n$ and obeys the following requirement:
    * Suppose this list is $answer = [a1, a2, a3, ... , an]$, then the list $[|a1 - a2|, |a2 - a3|, |a3 - a4|, ... , |an-1 - an|]$ has exactly $k$ distinct integers.
    * Return the list answer. If there multiple valid answers, return any of them.
    
    ```cpp
    // [1, n, 2, n - 2, 3, ...] will result in a n - 1 distinct diff
    // Time: O(n), Space: O(1)
    vector<int> constructArray(int n, int k) {
        vector<int> result(n, 0);
        int c = 0;
        
        for (int v = 1; v < n-k; v++) { // first produce acc order of number 
            result[c++] = v;
        }
        
        for (int i = 0; i <= k; i++) { // after n - k number, we have to produce alternating serise to reach [1, n, 2, n - 2]
            result[c++] = (i%2 == 0) ? (n-k + i/2) : (n - i/2);
        }
        
        return result;
    }
    ```

* Graph
    * BFS
    ```cpp
    void BFS(vector<vector<int>>& graph) {
        queue<int> q;
        vector<bool> visited(graph.size(), false);
        
        for(int i = 0; i < graph.size(); i++) {
            if(visited[i]) continue;
            
            q.push(i);
            
            while(!q.empty()) {
                int size = q.size();
                
                for(int j = 0; j < size; j++) {
                    int temp = q.front();
                    q.pop();
                    
                    /*Do something*/
                    
                    visited[temp] = true;
                    
                    // add its neighbour nodes
                    for(int node : graph[temp]) {
                        if(visited[node]) continue;
                        
                        q.push(node);
                    }
                }
            }
        }
    }
    ```

    * DFS
    ```cpp
    void DFS(vector<vector<int>>& graph) {
        vector<bool> visited(graph.size(), false);
        
        for (int start = 0; start < n; ++start) {
            if (!visited[start]) {
                stack<int> stk;
                stk.push(start);
                visited[start] = true;

                while (!stk.empty()) {
                    int node = stk.top();
                    stk.pop();
                    
                    /*Do something*/

                    for (int neigh : graph[node]) {
                        if (!visited[start]) {
                            stk.push(neigh);
                            visited[start] = true;
                        }
                    }
                }
            }
        }
    }
    ```

    * Topological sort
    ```cpp
    vector<bool> visited;
    vector<bool> on_path;
    bool find_cycle;
    vector<int> post_order;
    
    vector<int> findOrder(vector<vector<int>>& graph) {
        int n = graph.size();
        visited = vector<bool>(n, false);
        on_path = vector<bool>(n, false);
        post_order = vector<int>();
        find_cycle = false;
        
        for(int i = 0; i < numCourses; i++) {
            traverse(graph, i);
            if(find_cycle) return {}; // if find cycle, then it cannot be sorted
        }
        
        
        reverse(post_order.begin(), post_order.end()); // if we want parent to be the first, then we have to reverse this list
        return post_order;
    }
    
    void traverse(vector<vector<int>>& prerequisites, int start) {
        if(on_path[start]) { // find a loop
            find_cycle = true;
            return;
        }
        
        if(visited[start]) { // reached to a previous traversed point
            return;          // this is not necessarily a loop because we are in a directed graph
        }                   
        
        visited[start] = true; // one traversed never traversed again
        on_path[start] = true; // we are on a search path starting at start
        
        for(int neighbour : prerequisites[start]) {
            traverse(prerequisites, neighbour);
            if(find_cycle) return;
        }
        
        on_path[start] = false; // once we finish this traverse, we backtrack back
        post_order.push_back(start); // after we traverse all the child, we will add parent
        
    }
    ```

* Disjoint Set
    ```cpp
    class Union_set{
    public:
        Union_set(int size) {
            parents = vector<int>(size, 0);
            rank = vector<int>(size, 0);
            
            for(int i = 0; i < size; i++) {
                parents[i] = i;
            }
        }
        
        bool Union(int u, int v) {
            int pu = Find(u);
            int pv = Find(v);
            if(pu == pv) return false;
            
            if(rank[pu] == rank[pv]) { // if they have the same rank, then arbitrary choose one as the parent
                rank[pu]++;
                parents[pv] = pu;
            }else if(rank[pu] > rank[pv]) {
                parents[pv] = pu;
            }else {
                parents[pu] = pv;
            }
            
            return true;
        }
        
        // find parent and compress the path
        int Find(int u) {
            if(u != parents[u]) {
                parents[u] = Find(parents[u]);
            }
            
            return parents[u];
        }
        
    private:
        vector<int> parents;
        vector<int> rank;
    };
    ```

* change two number without extra variable
    ```cpp
    void (int& a, int& b) {
        a = a ^ b;
        b = a ^ b;
        a = a ^ b;
    }
    ```
### C++ Fun facts

* auto cast

```cpp
(5 / 2) = 2 // two int division will strickly cast to int
((double)5 / 2) = 2.5
```

* random number

```cpp
// rand() % range + start_point
v1 = rand() % 100;         // v1 in the range 0 to 99
v2 = rand() % 100 + 1;     // v2 in the range 1 to 100
v3 = rand() % 30 + 1985;   // v3 in the range 1985-2014 
```

* operator priority

```cpp
a & b == 0 // --> a & (b == 0)
```

### Common facts

* For a perfect square series
  $$
  [1, 4, 9, 16, ...]
  $$
  The difference of that series is a arithmetic progression
  $$
  [3, 5, 7, 9, ...]
  $$

* Summing a Geometric Series
    $$
        \sum_{k = 0}^{n - 1}{(ar^{k})} = a(\dfrac{1 - r^{n}}{1 - r}) 
    $$

* Bit operator
    ```
    x ^ 0s = x      x & 0s = 0      x | 0s = x
    x ^ 1s = ~x     x & 1s = x      x | 1s = 1s
    x ^ x = 0       x & x = x       x | x = x

    -x = ~x + 1

    x & (-x) = lower one
    x & (x - 1) = delete lower one
    ```