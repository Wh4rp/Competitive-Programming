# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        def get_number(node):
            num = ""
            while node:
                num = str(node.val) + num
                node = node.next
            return int(num)
        num1 = get_number(l1)
        num2 = get_number(l2)
        numAns = str(num1 + num2)[::-1]
        lista = []        
        for i in numAns:
            lista.append(ListNode(val=int(i)))
        for i in range(len(lista) - 1):
            lista[i].next = lista[i + 1]
        return lista[0]