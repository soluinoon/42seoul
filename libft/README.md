# Libft
[과제 요구사항](https://github.com/soluinoon/42seoul/files/11702454/en.subject.pdf)

본과정 첫번째 과제로 앞으로 과제에서 사용될 함수들을 만들어보는 서브젝트

## Mandatory
C의 라이브러리 함수들을 직접 구현해보기

## Bonus
포인터를 사용하여 LinkedList 구현해보기

## Build
main문을 만들고 빌드 후 실행

### ex) atoi 테스트
`main.c`
```c
#include "libft.h"
#include <stdio.h>

int main() {
	const char* str = "1234";

	printf("%d\n", ft_atoi(str));
	printf("%d\n", atoi(str));
}
```

#### MAC 기준 빌드
`gcc main.c ft_atio.c libft.h`

#### 실행
`./a.out`

#### 결과 확인
<img width="739" alt="Screen Shot 2023-06-09 at 2 04 56 PM" src="https://github.com/soluinoon/42seoul/assets/67910922/a259a8ce-160d-4202-8d3d-b504fcb03442">
