# ft_printf

Because ft_putnbr() and ft_putstr() aren't enough.

Проект первого круга основного обучения (42cursus) Школы 42/21 - написать усечённый `printf`. Получился сильно связанный, костыльный, не быстрый `ft_printf` - большое/частое число выделений памяти низводит улучшения.

Проверен по norminette версии 3.3.51.

Скачивание: `git clone --recursive https://github.com/stankudrow/ft_printf.git`.

# Руководства по семейству функций printf

* `man 3 printf` в терминале;
* [Wikipedia (en)](https://en.wikipedia.org/wiki/Printf_format_string);
* [IBM docs (en)](https://www.ibm.com/docs/en/ztpf/2020?topic=apis-fprintf-printf-sprintf-format-write-data);
* [Opennet printf (ru)](https://www.opennet.ru/man.shtml?topic=printf&category=3&russian=0);
* [Opennet vasprintf (ru)](https://www.opennet.ru/man.shtml?topic=vasprintf&category=3&russian=0) - низлежащая функция для ft_printf.

# Libft[x]

1. `cd ./ft_printf` - здесь требуется разместить библиотеку;
2. `git submodule add https://github.com/stankudrow/libftx` - библиотека подтянута из удалённого хранилища;
3. появился файл ***.gitmodules***

Шаги 1 и 2 можно объединить:

`git submodule add %remote_repo% %local_dir%`.

# Тестеры

1. https://github.com/Tripouille/printfTester - проходят на:
	* Ubuntu (TIMEOUT 40000);
	* Manjaro (TIMEOUT 30000 - можно меньше - нужна выверка);
	* MacOS (TIMEOUT 10000);
2. https://github.com/paulo-santana/ft_printf_tester - любопытные "выдатки":
	* Ubuntu - проходит;
	* Manjaro - не собрался;
	* MacOS - ошибки вывода, но ручные испытания показали работоспособность проекта;
3. https://github.com/Mazoise/42TESTERS-PRINTF - проходит на Manjaro/MacOS.