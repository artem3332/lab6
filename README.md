# Лабораторная работа №6. Безусловный экстремум.
<br>Выполнил студент группы 425</br>
<br>Романов Артем Александрович</br>
## Вариант № 18:
Найти точку минимума функции:
<br>![Image alt](https://github.com/artem3332/lab6/blob/master/raw/1.jpg)</br>
<br>![Image alt](https://github.com/artem3332/lab6/blob/master/raw/2.jpg)</br>
методом покоординатного спуска. Для одномерной минимизации использовать метод квадратичной ин-
терполяции. Для поиска интервала унимодальности использовать алгоритм  Свенна.
В окрестности точки минимума построить линии уровня и траекторию поиска (на одном графике).
## Теоретическая часть:
### Метод покоординатного спуска:
Для  построения минимизирующей последовательности используется формула (2). При этом вектор 
![Image alt](https://github.com/artem3332/lab6/blob/master/raw/3.jpg) определяется по правилу 
(циклический покоординатный спуск):
![Image alt](https://github.com/artem3332/lab6/blob/master/raw/4.jpg)
где (t)-целая часть числа t,![Image alt](https://github.com/artem3332/lab6/blob/master/raw/6.jpg) (единица стоит на j-ом месте), 
j=1,..,n.
<br>Число ![Image alt](https://github.com/artem3332/lab6/blob/master/raw/7.jpg) можно определять, например, следующим способом
![Image alt](https://github.com/artem3332/lab6/blob/master/raw/8.jpg)</br>
### Метод квадратичной интерполяции:
Здесь задаются пробные три пробные точки ![Image alt](https://github.com/artem3332/lab6/blob/master/raw/9.jpg) <br></br>
Для нахождения точки ![Image alt](https://github.com/artem3332/lab6/blob/master/raw/10.jpg) задается шаг h > 0 в положительном направлении от точки ![Image alt](https://github.com/artem3332/lab6/blob/master/raw/11.jpg), т.е ![Image alt](https://github.com/artem3332/lab6/blob/master/raw/12.jpg) и если ![Image alt](https://github.com/artem3332/lab6/blob/master/raw/13.jpg), то ![Image alt](https://github.com/artem3332/lab6/blob/master/raw/14.jpg), иначе ![Image alt](https://github.com/artem3332/lab6/blob/master/raw/15.jpg). <br></br>
Вычисляются значения функции в этих точках ![Image alt](https://github.com/artem3332/lab6/blob/master/raw/16.jpg),
строится квадратичный интерполяционный многочлен по трем точкам и находится его точка миимума по формуле
![Image alt](https://github.com/artem3332/lab6/blob/master/raw/17.jpg).<br></br>
Находится также точка ![Image alt](https://github.com/artem3332/lab6/blob/master/raw/18.jpg).
Если знаменатель в формуле для нахождения минимума квад- ратичного интерполяционного многочлена равен нулю, т.е. все 
три точки лежат на одной прямой рекомендуется выбрать за ![Image alt](https://github.com/artem3332/lab6/blob/master/raw/19.jpg)
и повторить нахождение точки ![Image alt](https://github.com/artem3332/lab6/blob/master/raw/20.jpg). <br></br>
Критерием окончания этого процесса является выполнение условий для заданного ϵ
![Image alt](https://github.com/artem3332/lab6/blob/master/raw/21.jpg) <br></br>
Если условия окончания не выполняются и ![Image alt](https://github.com/artem3332/lab6/blob/master/raw/22.jpg)
точка ![Image alt](https://github.com/artem3332/lab6/blob/master/raw/11.jpg) заменяется на точку ![Image alt](https://github.com/artem3332/lab6/blob/master/raw/23.jpg), в противном случае точка ![Image alt](https://github.com/artem3332/lab6/blob/master/raw/11.jpg) заменяется на ![Image alt](https://github.com/artem3332/lab6/blob/master/raw/20.jpg).
### Метод Свенна:
#### Начальный этап: 
1) Задать ![Image alt](https://github.com/artem3332/lab6/blob/master/raw/24.jpg) - произвольная точка.
2) Выбрать шаг h
#### Основной этап: 
<br>Шаг 1:</br>
Установить направление убывания целевой функции. Для этого надо взять ![Image alt](https://github.com/artem3332/lab6/blob/master/raw/25.jpg). Если ![Image alt](https://github.com/artem3332/lab6/blob/master/raw/26.jpg),
то надо поменять направление движения (h=-h и взять ![Image alt](https://github.com/artem3332/lab6/blob/master/raw/25.jpg)).
<br>Шаг 2:</br>
Вычислять ![Image alt](https://github.com/artem3332/lab6/blob/master/raw/27.jpg) в точках ![Image alt](https://github.com/artem3332/lab6/blob/master/raw/28.jpg), где ![Image alt](https://github.com/artem3332/lab6/blob/master/raw/29.jpg), k=2,3,...,n-1 до тех пор пока не придём в точку ![Image alt](https://github.com/artem3332/lab6/blob/master/raw/30.jpg), такую что ![Image alt](https://github.com/artem3332/lab6/blob/master/raw/31.jpg)
<br>Шаг 3:</br>
Установить начальный интервал локализации минимума ![Image alt](https://github.com/artem3332/lab6/blob/master/raw/32.jpg) и ![Image alt](https://github.com/artem3332/lab6/blob/master/raw/33.jpg).

## Практическая часть:
Программа состоит из четырех функций. Функция F это сама функция от двух переменных, interpolation1 и interpolation2 это функции в которых ищутся экстремумы функций одной переменной. В main реализован сам метод покоординатного спуска. Программа выводит на экран точку минимума , само значение функции и количество итераций.

## Результаты:

В результате работы программы у функции ![Image alt](https://github.com/artem3332/lab6/blob/master/raw/1.jpg) <br></br>
Был найден экстремум в точке (-5,0)(начальная точка (1,1)) за 7 итераций методами покоординатного спуска, квадратичной интерполяции, Свенна с точность 0.0001.
Ниже приведён рисунок с изображением линий уровня анализируемой функции и траектория поиска экстремума. 
![Image alt](https://github.com/artem3332/lab6/blob/master/raw/graf.png)



