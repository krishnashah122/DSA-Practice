# LFU Cache (Leetcode)
# Leetcode Link : https://leetcode.com/problems/lfu-cache/description/

# Time Complexity : O(1)
# Space Complexity : O(n)

class Node:
    def __init__(self, key, val):
        self.key = key
        self.val = val
        self.freq = 1
        self.prev = None
        self.next = None

class LinkedList:
    def __init__(self):
        # Dummy head and tail nodes
        self.head = Node(0, 0)
        self.tail = Node(0, 0)
        self.head.next = self.tail
        self.tail.prev = self.head
        self.len = 0
    
    def insert(self, node):
        temp = self.head.next
        node.prev = self.head
        node.next = temp
        temp.prev = node
        self.head.next = node
        self.len += 1
    
    def remove(self, node):
        prevNode = node.prev
        nextNode = node.next
        prevNode.next = nextNode
        nextNode.prev = prevNode
        self.len -= 1
    

class LFUCache:

    def __init__(self, capacity: int):
        self.capacity = capacity
        self.keyToNode = {} # To store key and the node which contains the same key
        self.freqToList = {} # To store frequency and LL whose nodes has same frequency
        self.minFreq = 1 # To keep track of the minimum frequency
        self.cacheSize = 0 # To keep track of the cache size
    
    def updateNode(self, node):
        # Delete the entry of node's key from keyToNode
        del self.keyToNode[node.key]
        # Remove the node from the LL corresponding to the prevFreq
        self.freqToList[node.freq].remove(node)

        # Update the minimum frequency
        if node.freq == self.minFreq and self.freqToList[node.freq].len == 0:
            self.minFreq += 1
        
        # Add the node in the LL which is corresponding to the node's frequency
        linkedList = LinkedList()
        if node.freq + 1 in self.freqToList:
            linkedList = self.freqToList[node.freq + 1]
        
        node.freq += 1
        linkedList.insert(node)
        self.freqToList[node.freq] = linkedList
        # Make a entry of the key and the node which has the same key
        self.keyToNode[node.key] = node

    def get(self, key: int) -> int:
        # If key is not present in keyToNode
        if key not in self.keyToNode:
            return -1
        
        # If key is present in keyToNode, update the node
        node = self.keyToNode[key]
        self.updateNode(node)
        
        return node.val

    def put(self, key: int, value: int) -> None:
        # If key is present in keyToNode
        if key in self.keyToNode:
            node = self.keyToNode[key]
            node.val = value
            self.updateNode(node)
            return
        else:
            # If the LFU cache is full
            if self.cacheSize >= self.capacity:
                # Remove the least frequently used node from freqToList & its entry from keyToNode
                listContaining = self.freqToList[self.minFreq]
                del self.keyToNode[listContaining.tail.prev.key]
                self.freqToList[self.minFreq].remove(listContaining.tail.prev)
                # Decrease the current size of the cache
                self.cacheSize -= 1
            
            # Increase the current size of the cache
            self.cacheSize += 1
            # Update the minimum frequency
            self.minFreq = 1
            # Insert the new node corresponding to its frequency & make a entry of node's key in keyToNode
            linkedList = LinkedList()
            if self.minFreq in self.freqToList:
                linkedList = self.freqToList[self.minFreq]
            
            node = Node(key, value)
            linkedList.insert(node)
            self.keyToNode[key] = node
            self.freqToList[self.minFreq] = linkedList

# Your LFUCache object will be instantiated and called as such:
# obj = LFUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)