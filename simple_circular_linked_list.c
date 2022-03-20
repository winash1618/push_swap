// //mine
// void printList(struct Node *head)
// {
//   struct Node *temp = head;
  
//   if (head != NULL)
//     printf("%d ", head->data);
//   head = head->next;
//   while (head != temp && head != NULL)
//   {
//       printf("%d ", head->data);
//       head = head->next;
//   }
// }
// // theirs
// void printList(struct Node *first)
// {
//     struct Node *temp = first;
 
//     // If linked list is not empty
//     if (first != NULL)
//     {
//         // Keep printing nodes till we reach the first node again
//         do
//         {
//             printf("%d ", temp->data);
//             temp = temp->next;
//         }
//         while (temp != first);
//     }
// }