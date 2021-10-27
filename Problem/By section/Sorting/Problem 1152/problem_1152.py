class Solution:
    # Time: O(n^3), Space: O(n)
    def mostVisitedPattern(self, username: List[str], timestamp: List[int], website: List[str]) -> List[str]:
        total_lst = {}
        
        for user, web, time in zip(username, website, timestamp):
            if user not in total_lst:
                total_lst[user] = []
                
            total_lst[user].append((web, time))
        
        max_count = 0
        cur_max = ""
        record = {}
        
        for user, lst in total_lst.items():
            lst.sort(key = lambda x : x[1])
            n = len(lst)
            Set = set()
            
            for i in range(n - 2):
                for j in range(i + 1, n - 1):
                    for k in range(j + 1, n):
                        result = ",".join([lst[i][0], lst[j][0], lst[k][0]])
                        
                        if result in Set:
                            continue
                        
                        Set.add(result)
                        
                        if result not in record:
                            record[result] = 1;
                        else:
                            record[result] += 1
                        
                        if record[result] == max_count:
                            cur_max = min(result, cur_max)
                        elif record[result] > max_count:
                            cur_max = result;
                            max_count += 1
                            
        return cur_max.split(",")
            