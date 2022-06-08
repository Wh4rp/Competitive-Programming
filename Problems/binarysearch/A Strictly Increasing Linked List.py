# class LLNode:
#     def __init__(self, val, next=None):
#         self.val = val
#         self.next = next
class Solution:
  def solve(self, head):
    ant = head
    while ant.next:
      if ant.val >= ant.next.val:
        return False
      ant = ant.next
    return True