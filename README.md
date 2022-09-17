# ft_printf

**Because ft_putnbr() and ft_putstr() aren't enough.**

Проект первого круга основного обучения (42cursus) Школы 42/21 - написать усечённый `printf`. Проверен по norminette 3.3.51.

Скачивание: `git clone --recursive https://github.com/stankudrow/ft_printf.git`.

## Manuals

* `man 3 printf` в терминале;
* [Wikipedia (en)](https://en.wikipedia.org/wiki/Printf_format_string);
* [IBM docs (en)](https://www.ibm.com/docs/en/ztpf/2020?topic=apis-fprintf-printf-sprintf-format-write-data);
* [Opennet printf (ru)](https://www.opennet.ru/man.shtml?topic=printf&category=3&russian=0);
* [Opennet vasprintf (ru)](https://www.opennet.ru/man.shtml?topic=vasprintf&category=3&russian=0) - основа ft_printf.

## Libft\[x\]

1. `cd ./ft_printf/ft_printf`;
2. `git submodule add https://github.com/stankudrow/libftx`;
3. ***.gitmodules***

Шаги 1 и 2 можно объединить: `git submodule add %remote_repo% %local_dir%`.

Примечание: подмодули сами не обновляются -> `git submodule update --remote`.

## Testers

1. [Tripouille/printfTester](https://github.com/Tripouille/printfTester);
2. [paulo-santana/ft_printf_tester](https://github.com/paulo-santana/ft_printf_tester);
3. [Mazoise/42TESTERS-PRINTF](https://github.com/Mazoise/42TESTERS-PRINTF).
