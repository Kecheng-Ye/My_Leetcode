class Solution:
    # Time: O(NKlogNK), Space: O(NK)
    def dfs(self, node, graph, visited, component):
        if visited[node]:
            return
        
        visited[node] = True
        component.append(node)
        
        for neighbor in graph[node]:
            if not visited[neighbor]:
                self.dfs(neighbor, graph, visited, component)
    
    def accountsMerge(self, accounts: List[List[str]]) -> List[List[str]]:
        graph = {}
        visited = {}
        email_to_account = {}

        # set up graph, visited 
        for account in accounts:
            emails = account[1:]
            first_email = emails[0] # piviot point
            for email in emails:
                # undirected graph for two emails
                graph.setdefault(email, set()).add(first_email)
                graph.setdefault(first_email, set()).add(email)
                
                visited[email] = False
                email_to_account[email] = account[0] # email to name mapping
        
        output = []
        
        for email, account in email_to_account.items():
            if visited[email]:
                continue
                
            # visited dict ensures that DFS gets called for every component
            # and NOT on every node
            nodes = [] # to fill all nodes (emails) in the component
            self.dfs(email, graph, visited, nodes)
            output.append([account] + sorted(nodes))
            
        return output