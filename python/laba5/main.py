from TDate import *

n = int(input("Введите n: "))
lst = [TDate1(input()) for i in range(n)]
m = int(input("Введите m: "))
lst += [TDate2(input()) for j in range(m)]
print(max(lst, key=lambda x: x.get_days_since_year_0()))
date1 = input("Введите нижний предел диапазона дат: ")
date2 = input("Введите верхний предел диапазона дат: ")
print("Даты, которые входят в заданный диапазон")
for i in lst:
    if i.is_in_time_interval(date1, date2):
        print(i)
print("Дата, увеличенная на заданное количество времени: ", lst[0].increase_date(1, 1, 1))
print("Дата, уменьшенная на заданное количество времени: ", lst[1].decrease_date(1, 1, 1))
