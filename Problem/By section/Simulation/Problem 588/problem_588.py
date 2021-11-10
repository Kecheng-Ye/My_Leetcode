class FileSystem:

    def __init__(self):
        self.root = directory('root')

    def ls(self, path: str) -> List[str]:
        parent, child_name = self.path_name_resolution(path)
        
        if not child_name:
            return parent.get_content()
        else:
            target = parent.find_inode(child_name)
            
            if isinstance(target, file):
                return [target.name]
            else:
                return target.get_content()

    def mkdir(self, path: str) -> None:
        parent, child_name = self.path_name_resolution(path)
        
        new_dir = directory(child_name)
        parent.add_inode(new_dir)

    def addContentToFile(self, filePath: str, content: str) -> None:
        parent, child_name = self.path_name_resolution(filePath)
        
        target_file = parent.find_inode(child_name)
        if not target_file:
            target_file = file(child_name)
            parent.add_inode(target_file)
            
        target_file.add_content(content)

    def readContentFromFile(self, filePath: str) -> str:
        parent, child_name = self.path_name_resolution(filePath)
        
        target_file = parent.find_inode(child_name)
        return target_file.get_content()
        
    def path_name_resolution(self, path):
        sep_dirs = path.split("/")
        n = len(sep_dirs)
        base_node = self.root
        
        for i in range(n - 1):
            if not base_node.find_inode(sep_dirs[i]):
                new_dir = directory(sep_dirs[i])
                base_node.add_inode(new_dir)
            
            base_node = base_node.find_inode(sep_dirs[i])
        
        return base_node, sep_dirs[n - 1]
        
    
class inode:
    def __init__(self, name):
        self.name = name
        
class file(inode):
    def __init__(self, name):
        super().__init__(name)
        self.content = ""
    
    def add_content(self, content):
        self.content += content
    
    def get_content(self):
        return self.content
    
class directory(inode):
    
    def __init__(self, name):
        super().__init__(name)
        self.dir = {}
        
    def add_inode(self, new_inode):
        self.dir[new_inode.name] = new_inode
        
    def find_inode(self, target_str):
        if target_str not in self.dir:
            return None
        else:
            return self.dir[target_str]
        
    def get_content(self):
        return sorted(self.dir.keys())
    

# Your FileSystem object will be instantiated and called as such:
# obj = FileSystem()
# param_1 = obj.ls(path)
# obj.mkdir(path)
# obj.addContentToFile(filePath,content)
# param_4 = obj.readContentFromFile(filePath)