﻿//Постфиксной формой записи(ОПЗ) выражения a◦b называется запись, в которой знак операции размещен за операндами ab◦.
//Например:
//Обычная запись Обратная польская запись
//a - b a b -
//a * b + c a b * c +
//a * (b + c) a b c + *
//(a + c) / (c * a - d) a c + c a * d - /
//Описать функции, которая вычисляет значение заданного выражения.Входные данные.В первой строке содержит обратную польскую запись арифметического выражения.Все операнды целые положительные числа.Выходные данные.Вывести результат вычисления ОПЗ.Технические требования.Используются знаки операций : +, -, *, / .Примеры
//input.txt output.txt
//3 1 + 4
//12 5 * 10 - 50
//1 2 30 + *32
//2 10 + 2 4 + 6 – 2 / 6
//12 6 6 / / 2 /
