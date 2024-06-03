# LRU Cache (Leetcode)
# Leetcode Link : https://leetcode.com/problems/lru-cache/description/

# Time Complexity : O(1)
# Space Complexity : O(n)

class Node:
    def __init__(self, key, value):
        self.key = key
        self.val = value
        self.prev = None
        self.next = None

class LinkedList:
    def __init__(self):
        self.head = None
        self.tail = None
        self.len = 0
    
    def insert(self, node):
        # If LL is empty
        if self.head == None:
            self.head = self.tail = node
        else:
            node.next = self.head
            node.prev = None
            self.head.prev = node
            self.head = node
        
        self.len += 1
    
    def remove(self, node):
        # If LL has only one node
        if self.head == self.tail:
            self.head = self.tail = None
        # If node is the head of LL
        elif node.prev == None:
            self.head = node.next
            node.next.prev = None
        # If node is the tail of LL
        elif node.next == None:
            self.tail = node.prev
            node.prev.next = None
        # If node is in the middle of LL
        else:
            node.prev.next = node.next
            node.next.prev = node.prev
        
        self.len -= 1

class LRUCache:

    def __init__(self, capacity: int):
        self.capacity = capacity
        self.map = {}
        self.cache = LinkedList()

    def get(self, key: int) -> int:
        # If key is not in the map, return -1
        if key not in self.map:
            return -1
        
        node = self.map[key]
        # Remove the node from the cache LL
        self.cache.remove(node)
        # Insert the node in the beginning of the cache LL
        self.cache.insert(node)

        return node.val

    def put(self, key: int, value: int) -> None:
        # If key is present in the map
        if key in self.map:
            # Remove the node having that key
            self.cache.remove(self.map[key])
        
        # Insert the new node in the beginning of the cache LL
        newNode = Node(key, value)
        self.cache.insert(newNode)
        self.map[key] = newNode

        # If the length of the cache has become greater than its capacity
        if self.cache.len > self.capacity:
            # Delete the entry of key of tail from the map
            del self.map[self.cache.tail.key]
            # Remove the tail node from the cache LL
            self.cache.remove(self.cache.tail)


# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)