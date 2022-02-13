<center><h1>get next line</h1></center>

-----------------------------------------------------------------------
> |   Имя программмы        | get_next_line                           |
> |-------------------------|-----------------------------------------|
> |   Прототип              | int get_next_line(int fd, char **line); |
> |   Файлы для сдачи       | get_next_line.c, get_next_line_utils.c, get_next_line.h                                                                     |
> |   Параметры             | #1. файловый дескриптор для чтения; #2. Значение, куда это будет прочитано.                                                            |
> |   Возвращаемое значение | (1) Если строка была прочитана, (0) Если был достигнут EOF, (-1) Если случилась ошибка.                                                |
> |   Внешние функции.      | read, malloc, free                      |
> |   Описание              | Напишите функцию, которая возвращает строку, прочитанную из файлового дескриптора, без символа новой строки.                                |
-----------------------------------------------------------------------
</br>

- Вызов вашей функции `get_next_line` в цикле позволит вам читать текст, доступный в файловом дескрипторе, по одной строке за раз, пока не будет достигнут конец файла `EOF`(End of File).

- `Строкой` мы называем последовательность символов, которые заканчиваются на символе `\n` (код `ascii` `0x0a`) или на конце файла `EOF`(End of File).

- Первый параметр принимаемый функцей - это дескриптор файла, который будет использоваться для чтения.

- Второй параметр принимаемый функцей - это адрес указателя на символ, который будет использоваться для сохранения строки, прочитанной из файлового дескриптора.

- Возвращаемое значение может быть `1`, `0` или `-1` в зависимости от того, была ли строка прочитана, когда чтение было завершено или произошла ошибка.

- Убедитесь, что ваша функция хорошо себя ведет при чтении из файла и при чтении из стандартного ввода.

- Ваша собственная библиотека `libft` не разрешена для этого проекта. Вы должны добавить файл `get_next_line_utils.c`, который будет содержать функции, необходимые для работы `get_next_line`.

- Ваша программа должна компилироваться с флагом `-D BUFFER_SIZE=xx.`, который будет использоваться в качестве размера буфера для вызовов чтения в вашей `get_next_line`. Это значение может и будет изменено вашими оценщиками или программой `moulinnette`.

- Компиляция будет производиться следующим образом: ` gcc -Wall -Wextra -Werror -D BUFFER_SIZE=32 get_next_line.c get_next_line_utils.c `.

- Ваш `read` должен использовать `BUFFER_SIZE`, определенный во время компиляции, для чтения из файла или из чтения из стандартного потока ввода `stdin`.

- В заголовочном файле `get_next_line.h` у вас должен быть как минимум прототип функции `get_next_line` и макрос `BUFF_SIZE`, позволяющий выбрать размер буфера чтения для функции чтения. Это значение будет изменено во время защиты, чтобы оценить силу вашей функции.

- Мы считаем, что `get_next_line` имеет неопределенное поведение, если между двумя вызовами один и тот же файловый дескриптор переключается на другой файл до того, как на первом `fd` будет достигнут `EOF`.

- `lseek` является недопустимой функцией. Чтение файла необходимо производить только один раз.

- Наконец, мы считаем, что `get_next_line` имеет неопределенное поведение при чтении из двоичного файла. Однако при желании вы можете сделать такое поведение последовательным.

- Глобальные переменные запрещены.