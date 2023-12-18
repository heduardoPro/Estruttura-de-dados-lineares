class HashTable:
    def __init__(self, size):
        self.size = size
        self.table = [None] * size

    def hash(self, key):
        return hash(key) % self.size

    def insert(self, key, value):
        index = self.hash(key)
        self.table[index] = value

    def get(self, key):
        index = self.hash(key)
        return self.table[index]

    def remove(self, key):
        index = self.hash(key)
        self.table[index] = None
    
    def __str__(self) -> str:
        return str(self.table)
    
