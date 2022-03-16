Задача
На входе функция получает параметр n - натуральное число.
Необходимо сгенерировать n - массивов, заполнить их случайными числами, каждый массив имеет случайный размер.
Размеры массивов не должны совпадать.Далее необходимо отсортировать массивы.
Массивы с четным порядковым номером отсортировать по возрастанию, с нечетным порядковым номером - по убыванию.
На выходе функция должна вернуть массив с отсортированными массивами.

Примечания к решению :
1)Задача решена для случая, в котором массивы будут содержать данные типа int. Однако, его можно изменить путём изменения DATA_TYPE.
2)Размеры случайных массивов ограничены максимумом элементов в 8 элементов для наглядности. Убрать ограничения можно путём удаления "%8 + 1" после rand() в строках
