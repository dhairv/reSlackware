reSlackware - кросскомпилятор+"работающий рецепт" сборки Slackware в духе LFS-book.
Фактически имеем 3 уровня, хотя "формально-абстрактно" - 4(0,1,2,3) :

_STAGE_01 - построение кросскомпилятора (0),
 и с помощью него минимальной target-системы (1).

_STAGE_2  - "рост"(компилируем и сразу ставим пакеты в систему),
 инсталяция новоиспеченной Slackware на основе полученной пакетной базы (2).

_STAGE_3 - сборка всего дистрибутива (3), и если что-то не так, то возврат к _STAGE_2.


_STAGE_01
В качестве host/build-системы я использовал чистую,"дефолтную" Slackware64-14.1
(можно current, но она "на_роликах" и результат не гарантирован;
 для 14.2 - нужна замена gcc, mpc, gmp, mpfr из 14.1 или из current).
Устанавливать, нужно с инструментами для разработки, gcc, binutils, make и пр.
(проще установить по типу "Всё", все-равно потом сносить).
Если интересно проверить работу "канадского кросскомпилятора",
то например, можно взять host/build 32bit и строить target 64bit.

Итак, установлена Slackware64-14.1
Заменено: pkgtools из 13.37 т.к. не пробует писать в /run.
Скачиваем, распаковываем reSlackware.
Для удобства-наглядности я перенес/переименовал reSlackware в /_STAGE_01
(в любом случае далее подразумевается /_STAGE_01 = reSlackware/ )

cd /_STAGE_01

Поправляем, если нужно, скрипт get_tarballs.
. ./get_tarballs
(сигнатуры пакетов находим и проверяем сами, что в духе двухфакторной проверки)
Открываем скрипт 2b_target, поправляем, если нужно, платформы, битность, флаги, сохраняем
(отмечу: если host=build=target то кросскомпиляция по "канадскому кресту" не проходит,
поэтому-то host/build=x86_64-slackware-linux, target=x86_64-reslackware-linux).
. ./2b_target_sysroot
ждем ...
, если все OК, то кросскомпилятор собран и лежит /_STAGE_01/crosstool,
а собранная им target-система  лежит /_STAGE_01/_st1_sysroot

Далее уровень _STAGE_2
Смотрим /_STAGE_01/_st1_sysroot/_mk_st2/README.md
и /_STAGE_01/_st1_sysroot/_mk_st2/2b_st2

