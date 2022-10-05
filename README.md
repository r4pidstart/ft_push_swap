# Push_swap - Because Swap_push isn’t as natural
### This project will make you sort data on a stack, with a limited set of instructions, using
the lowest possible number of actions. To succeed you’ll have to manipulate various
types of algorithms and choose the most appropriate solution (out of many) for an
optimized data sorting.
*Version : 6*

---

#### Mandatory part

##### The rules
• You have 2 stacks named a and b.

• At the beginning:

	◦ The stack a contains a random amount of negative and/or positive numbers
	which cannot be duplicated.

	◦ The stack b is empty.

• The goal is to sort in ascending order numbers into stack a. To do so you have the
following operations at your disposal:

	sa (swap a): Swap the first 2 elements at the top of stack a.
	Do nothing if there is only one or no elements.

	sb (swap b): Swap the first 2 elements at the top of stack b.
	Do nothing if there is only one or no elements.

	ss : sa and sb at the same time.

	pa (push a): Take the first element at the top of b and put it at the top of a.
	Do nothing if b is empty.

	pb (push b): Take the first element at the top of a and put it at the top of b.
	Do nothing if a is empty.

	ra (rotate a): Shift up all elements of stack a by 1.
	The first element becomes the last one.

	rb (rotate b): Shift up all elements of stack b by 1.
	The first element becomes the last one.

	rr : ra and rb at the same time.

	rra (reverse rotate a): Shift down all elements of stack a by 1.
	The last element becomes the first one.

	rrb (reverse rotate b): Shift down all elements of stack b by 1.
	The last element becomes the first one.

	rrr : rra and rrb at the same time.

##### Program name
* push_swap
##### External functs. 
* read, write, malloc, free,
exit
* ft_printf and any equivalent
YOU coded
##### Description
* Sort stacks
* You have to write a program named push_swap that takes as an argument the stack
a formatted as a list of integers. The first argument should be at the top of the
stack (be careful about the order).
* The goal is to sort the stack with the lowest possible number of operations. During
the evaluation process, the number of instructions found by your program will be
compared against a limit: the maximum number of operations tolerated. If your
program either displays a longer list or if the numbers aren’t sorted properly, your
grade will be 0.

#### Bonus part
##### Program name
* checker
##### External functs. 
* read, write, malloc, free,
exit
* ft_printf and any equivalent
YOU coded
##### Description
* Execute the sorting instructions
* Write a program named checker that takes as an argument the stack a formatted
as a list of integers. The first argument should be at the top of the stack (be careful
about the order). If no argument is given, it stops and displays nothing.
* If after executing those instructions, the stack a is actually sorted and the stack b
is empty, then the program must display "OK" followed by a ’\n’ on the standard
output.
* In every other case, it must display "KO" followed by a ’\n’ on the standard output.
---

간단하게 설명하자면, **인자로 받은 숫자들을 두개의 스택(?)과 주어진 명령어만으로 명령횟수를 최소로 하여 정렬시키는 과제이다.**
해당 과제에서는 내가 전처리하는데에 얼마나 많은 시간복잡도가 요구되건간에, 결국 명령어의 횟수만 최소로 하면 된다.

일단, 무언가를 '정렬'하기를 요구받았기에, 내가 알고있는 정렬방법들을 적용할 수 있는가 생각해보았다.
먼저 스택 두개를 이용하기에 가장 먼저 떠오른 것은 머지소트였다. 이는 입력과 관계없이 항상 일관된 퍼포먼스를 보여주기에, 어떤 경우에서라도 과제 통과기준을 만족시킬 수 있지 않을까 하는 생각에서였다. 그러나, 계산해보니 별 다른 최적화가 없을 때에 6천번정도의 명령이 필요할 것으로 판단되어, 수백개 이상의 명령어를 더 줄일 수 있다는 자신이 없어 일단 다른 방법을 찾았다.

전처리를 이용해 최대한 원소들을 균등하게 분할할 수 있다는 것이 보장되기에, 퀵소트로도 시도해보았지만, 머지소트와 비슷한 횟수로 정렬할 수 있을 것이라 판단했다.

마지막으로 생각해본 건 라딕스 소트인데, 수들을 압축하기만 하면 충분히 좋은 효율을 낼 수 있을 것 같아 시도해보았다.
계산했던 흔적들이 지워졌으나, 500개의 원소를 n진수로 k자리로 표현한다고 했을 때, 어떠한 조합에서라도 6천번 이상의 명령 횟수가 필요해서 포기했던 것으로 기억한다.

며칠동안 붙잡고 고민을 하면서 평가를 다니다가, 해당 과제를 평가할 수 있는 기회를 갖게되었는데, 알려진 정렬 알고리즘이 아니라 독특한 방법을 사용해 과제를 해결하신 분이 계셨다.
이 분은 그리디한(?) 방법으로 해결하셨는데, 500개 기준으로 4천번 초반정도의 퍼포먼스를 보일 정도로 강력하여 해당 방법을 이용해보기로 했다.

<img width="333" alt="image" src="https://user-images.githubusercontent.com/67845112/194139064-3f6c528b-6614-4842-af6d-a77c84b451fb.png">
생각해보면, 우리가 사용하는 스택은 일반적으로 통용되는 스택이 아니라, 위 아래가 모두 뚫려있다고 상상할 수 있는 어떠한 자료구조이다.
대신 아래로 넣는 작업은 위로 넣는 것보다 비용이 두배 더 든다는 것.
하여튼 우리는 스택을 4개 가지고 있는 것이다.

남은 스택 3개를 이용해, 입력받은 인자를 3개의 그룹으로 균등하게 나눠준다.
추후 그리디한 방법을 이용하기에, 이 방식으로 비슷한 위치에 들어갈 것들을 모아주는것이 약 25%정도 빠른 수행결과를 기대할 수 있었다. 
<img width="1422" alt="image" src="https://user-images.githubusercontent.com/67845112/194140028-3f210b87-f6fa-486e-91de-4c37fff34d2d.png">

다 나눈 뒤엔, 이런 모양이 되는데, 결국 수행이 끝난 뒤에는 A스택으로 모든 원소가 모여야하기에, 일단 B스택으로 모아주었다.
<img width="1422" alt="image" src="https://user-images.githubusercontent.com/67845112/194140296-dfb0894c-b891-4e75-8992-118381455324.png">




