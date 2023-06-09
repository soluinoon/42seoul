# Get_Next_Line
[과제 요구사항](https://github.com/soluinoon/42seoul/files/11702473/en.subject.1.pdf)

개행 단위로 fd에서 값을 읽어들이는 함수를 만드는 서브젝트

## Mandatory
하나의 fd에서 개행 단위로 읽는 함수 만들어보기

## Build
main문을 만들고 빌드 후 실행

### ex) atoi 테스트
`main.c`
```c
int	main(void)
{
char	*line;
int		i;
int		fd1;
fd1 = open("./test.txt", O_RDONLY);
i = 1;
while (i < 4)
{
	line = get_next_line(fd1);
	printf("line [%02d]: %s", i, line);
	free(line);
    i++;
}

close(fd1);
return (0);
}
```

#### MAC 기준 빌드
`gcc -Wall -Werror -Wextra -D BUFFER_SIZE=xx get_next_line.c get_next_line_utils.c`

* `BUFFER_SIZE` : 버퍼 사이즈 지정

#### 실행
`./a.out`
