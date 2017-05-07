# Контролно 1

Баскетболната асоциация NBA иска да си направи система за следене на отборите и играчите в лигата. За целта трябва да разработите система, която да пази информация за следните обекти:

 * Отбор(Team)
 * Играч(Player)
 * Треньор(Coach)
 * Член от персонала(StaffMember)

Един играч трябва да има име(name), възраст(age), вкарани точки средно за игра(points per game - ppg), асистенции средно за игра(assists per game - apg), както и борби средно за игра(rebounds per game - rpg). Последните три характеристики трябава да са реални числа. Също трябва да пазите по някакъв начин и заплатата на един играч - реално число.

Един треньор се характеризира с име, възраст, години опит в лигата и заплата.

Член от персонала има име и заплата.

Един отбор се характеризира с име, брой титли, играчи(максимум 12 може да има), един треньор и персонал(няма лимит на бройката).

За всички класове, трябва да реализирате голямата четворка и getters & setters за всяко поле(освен полета, които ползвате само вътре в класа).

Също трябва да реализарате следните неща:
 * трябва да предефинирате оператор << за Player, Coach и StaffMember;
 * към един отбор трябва да може да се добавя играч или член от персонала(направете функция add и предефинирайте оператор +=);
 * към един отбор трябва да може да се премахва играч или член от персонала(направете функция remove и предефинирайте оператор -=);
 * класът Team трябва да има функция, която връща общата сума, която отбора дължи на играчите, треньора и персонала.

