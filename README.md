# push_swap

## make file issue
- If any of the file in makefile have any changes you just need to run make reload it. but in my case it was not happening, because i was not checking the object file before running the $(NAME_M) rule this made my make file say no need to run the make file eventhough there is some changes i made. Inorder to correct this error i changed $(OBJ) to $(SRC_M:.c=.o) and checked $(OBJ) before running the $(NAME) rule.

## testers
- https://github.com/o-reo/push_swap_visualizer
- https://github.com/mharriso/school21-checklists/blob/master/ng_2_push_swap.pdf
- https://github.com/lmalki-h/push_swap_tester

## tips

- inorder to run push_swap in docker
- type start from push_swap directory
- then do make re
- valgrind ./push_swap 3 2 6 4
- debugging gcc -g *.c
- lldb ./push_swap 2 6 1 0 
- if you are using lldb do not run it with ./push_swap that is made by makefile its not working, i don't know why. 
- for lldb use this command first: gcc -g push_swap*.c small_sort.c big_sort.c circular_linked_list_utils.c ft_split.c libft_functions.c
- then lldb ./a.out 3 12 5 as normal

## Resources
- https://sharkigamers.github.io/pushswap_epitech_project/ They are explaining how to do this project using circular linked list.
- https://www.geeksforgeeks.org/linked-list-set-1-introduction/ Linked list explanation.
- https://github.com/gkintana/42-push_swap/blob/main/sources/sort_large.c
- https://medium.com/nerd-for-tech/push-swap-tutorial-fa746e6aba1e
- https://github.com/kurval/42-push_swap/tree/master/includes
- https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a


## How to do it.

- TThe project can be done by multiple different way:

  - By using array.

  - By using simply linked list.

  - By using doubly linked list.

  - By using doubly circular linked list.

- The project Pushswap is quite simple when you understand how to do. It is splited into 3 parts:

  - Linked List the l_a with args passed as parameters.

  - Actions asked on the subject.

  - Algorithm radix sort by Bit Shifting method.

## testers 
- https://github.com/lmalki-h/push_swap_tester

## visualizer
- https://github.com/o-reo/push_swap_visualizer
