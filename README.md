# Push_swap - Because Swap_push isn’t as natural
#### This project will make you sort data on a stack, with a limited set of instructions, using the lowest possible number of actions. To succeed you’ll have to manipulate various types of algorithms and choose the most appropriate solution (out of many) for an optimized data sorting.

*Version : 6*

---

### Mandatory part

<details>
    <summary>The rules</summary>

* You have 2 stacks named a and b.

* At the beginning:

	◦ The stack a contains a random amount of negative and/or positive numbers
	which cannot be duplicated.

	◦ The stack b is empty.

* The goal is to sort in ascending order numbers into stack a. To do so you have the
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
</details>

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

### Bonus part
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

간단하게 설명하자면, **인자로 받은 숫자들을 두개의 스택(?)과 주어진 명령어만으로 명령횟수를 최소로 하여 정렬시키는 과제**이다.
해당 과제에서는 내가 전처리하는데에 얼마나 많은 시간복잡도가 요구되건간에, 결국 명령어의 횟수만 최소로 하면 된다.

#### 어떻게 정렬했는가?

* 일단, 무언가를 '정렬'하기를 요구받았기에, 내가 알고있는 정렬방법들을 적용할 수 있는가 생각해보았다.
먼저 스택 두개를 이용하기에 가장 먼저 떠오른 것은 머지소트였다. 이는 입력과 관계없이 항상 일관된 퍼포먼스를 보여주기에, 어떤 경우에서라도 과제 통과기준을 만족시킬 수 있지 않을까 하는 생각에서였다. 그러나, 계산해보니 별 다른 최적화가 없을 때에 6천번정도의 명령이 필요할 것으로 판단되어, 수백개 이상의 명령어를 더 줄일 수 있다는 자신이 없어 일단 다른 방법을 찾았다.

* 전처리를 이용해 최대한 원소들을 균등하게 분할할 수 있다는 것이 보장되기에, 퀵소트로도 시도해보았지만, 머지소트와 비슷한 횟수로 정렬할 수 있을 것이라 판단했다.

* 마지막으로 생각해본 건 라딕스 소트인데, 수들을 압축하기만 하면 충분히 좋은 효율을 낼 수 있을 것 같아 시도해보았다.
계산했던 흔적들이 지워졌으나, 500개의 원소를 n진수로 k자리로 표현한다고 했을 때, 어떠한 조합에서라도 6천번 이상의 명령 횟수가 필요해서 포기했던 것으로 기억한다.

* 며칠동안 붙잡고 고민을 하면서 평가를 다니다가, 해당 과제를 평가할 수 있는 기회를 갖게되었는데, 알려진 정렬 알고리즘이 아니라 독특한 방법을 사용해 과제를 해결하신 분이 계셨다. 이 분은 그리디한(?) 방법으로 해결하셨는데, 500개 기준으로 4천번 초반정도의 퍼포먼스를 보일 정도로 강력하여 해당 방법을 이용해보기로 했다.

<img width="333" alt="image" src="https://user-images.githubusercontent.com/67845112/194139064-3f6c528b-6614-4842-af6d-a77c84b451fb.png">

* 생각해보면, 우리가 사용하는 스택은 일반적으로 통용되는 스택이 아니라, 위 아래가 모두 뚫려있다고 상상할 수 있는 어떠한 자료구조이다. 대신 아래로 넣는 작업은 위로 넣는 것보다 비용이 두배 더 든다는 것. 하여튼 우리는 스택을 4개 가지고 있는 것이다.

* 남은 스택 3개를 이용해, 입력받은 인자를 3개의 그룹으로 균등하게 나눠준다. 추후 그리디한 방법을 이용하기에, 이 방식으로 비슷한 위치에 들어갈 것들을 모아주는것은 최악의 상횡에서 명령어의 상한을 낮춰주는 효과가 있고, 이를 통해 약 25%정도 빠른 수행결과를 기대할 수 있었다.

<img width="1422" alt="image" src="https://user-images.githubusercontent.com/67845112/194140028-3f210b87-f6fa-486e-91de-4c37fff34d2d.png">

* 다 나눈 뒤엔, 이런 모양이 되는데, 결국 수행이 끝난 뒤에는 A스택으로 모든 원소가 모여야하기에, 일단 B스택으로 모아주었다.

<img width="1422" alt="image" src="https://user-images.githubusercontent.com/67845112/194140296-dfb0894c-b891-4e75-8992-118381455324.png">

* 이제, 전처리가 얼마나 걸리든 상관없다는 조건을 이용해, B스택의 모든 원소에 대해서 A스택의 적절한 위치, 즉 정렬된 위치로 옮기기 위해서 드는 비용을 계산한다. B스택의 어떠한 원소를 A스택의 어떠한 위치로 옮기기 위해서는, 그 원소를 B스택의 맨 위로 옮기는데 드는 비용, A스택의 적절한 위치가 맨 위가 되도록 드는 비용의 합이 필요하다. 이 방식으로 계산한 비용이 가장 작은 원소를 A로 옮겼다.

<img width="1422" alt="image" src="https://user-images.githubusercontent.com/67845112/194145432-a2b754ee-cfdb-4086-ba6b-d060520d817e.png">

* 지금이 최적의 선택이라고 다음의 선택까지 최적이라는 보장은 절대 없지만, 해당 과제는 이런 간단한 방법으로도 어렵지 않게 풀린다. 우리에게 시간은 많으므로, 원소가 n개일때 스택 전체의 비용을 계산하는 시간복잡도는 O(n)인데, n<=500이므로 충분히 지금 선택과 다음 선택까지 최적인 것도 확인할 수 있을 것 같다. 조금 무리하면 3번의 수행까지도? *O(n^4/8)?* 

* 이러면 명령어 실행 횟수가 유의미하게 줄어들 것 같긴 한데, 이미 통과하기엔 충분하므로 더 이상 시간을 쓰고싶진 않아 그만뒀다. 

* 누군가 이 글을 읽고 시도해본다면, 결과를 공유해주길 바라겠다.
- - -

보너스 과제는 단순히 우리가 push_swap을 만들 때 사용한 스택 구현체를 이용해서, 직접 해당 명령을 수행하는 코드만 만들면 된다.
	
이곳에서 처음보는 보너스다운 보너스.

여담이지만, cpp에서 stack을 사용하던 경험때문에, 비슷하게 만들어보려고 시도했으나 오히려 더 비효율적인 결과가 나오더라.
```c
int	dlist(int stack, int cmd, int target)
{
	if (cmd == init)
		return (dl_init(get_list(stack)));
	else if (cmd == push_back)
		return (dl_push_back(get_list(stack), target));
	else if (cmd == push_front)
	...
	return (-1);
}

// 대충 이런 식으로 쓸 수 있다.
dlist(0, push_front, dlist(0, pop_back, 0));
```
어디선가 c로도 객체지향으로 코드를 짤 수 있다길래, 객체 비슷한걸 만들어보고 싶었는데 오히려 추후 수정하기만 더 힘들더라.
	
조오금 후회했다. 다른 사람들은 어떻게 하나 공부좀 해봐야겠다.

---

<img width="649" alt="image" src="https://user-images.githubusercontent.com/67845112/194144614-497651cb-4c60-4fe3-bc8c-e0dd32cd8019.png">

<img width="642" alt="image" src="https://user-images.githubusercontent.com/67845112/194142083-9a919d4f-62ef-410f-b9cf-9545f5419575.png">

<img width="714" alt="image" src="https://user-images.githubusercontent.com/67845112/194142190-87169b39-b300-4c24-8b93-2407fe0eb016.png">

[![Hits](https://hits.seeyoufarm.com/api/count/incr/badge.svg?url=https%3A%2F%2Fgithub.com%2Fr4pidstart%2Fft_push_swap&count_bg=%23000000&title_bg=%23555555&icon=&icon_color=%23E7E7E7&title=hits&edge_flat=false)](https://hits.seeyoufarm.com)
