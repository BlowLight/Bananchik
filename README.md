
Я НАУЧИЛАСЬ ПОЛЬЗОВАТЬСЯ ГИТХАБОМ НАКАНЕЦА
---------------------------
--------------------------
Теперь о программе
--------
Моя тема - **"Генерация лабиринтов"**. Оч скучно как-то. Поэтому я решила сделать это в виде игры, где банан должен найти свою любовь в виде 5 сердечек и тогда он будет счастлив (и Вы тоже). При этом, когда он "съедает" сердечко, то лабиринт заново генерируется и появляется новое сердечко в новом месте, а банан остается на своем. Также в лабиринте рандомно генерируются цветы и камни. Цветы - чтобы жизнь малиной не казалась. Они отнимают жизнь у банана, которой у него в самом начале игры всего 5. Камни не дают бананчику пройти. 

Чтобы получить подробное описание во время игры, игрок может нажать **TAB** и получит информацию о горячих клавишах, времени, количестве сердечек и жизни. 

![](http://cs636827.vk.me/v636827858/abb1/V_argS9uPkg.jpg)

Если игрок не доволен положением дел, а именно: расстановкой сердечка, цветов и камней, то он может сгенерировать лабиринт заново с помощью нажатия пробела. Однако при этом у бананчика отнимется 2 жизни (плак плак).

![](http://cs636827.vk.me/v636827858/abb9/IFUpTM3eiVM.jpg)

----------------------------
 Игра закончится, если вы потратите все жизни или если вы соберете 5 сердечек. 
 
________________

![](http://cs636827.vk.me/v636827858/aba1/tdAWrgz_dgQ.jpg)

>**Меню игры:**
> - Начать игру
> - О программе 
> - Выход

Тут, думаю, все понятно.

Камера привязана к персонажу (банану), поэтому чтобы просмотреть остальную часть карты, что нам не видна, мы можем воспользоваться клавишами **W**, **A**, **S**, **D**.

Для генерации лабиринта я использовала [алгоритм Эйлера][1] только чуть-чуть по-своему.

Ну, вроде, эт все.

[1]: https://habrahabr.ru/post/176671/
