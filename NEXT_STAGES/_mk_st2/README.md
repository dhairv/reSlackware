##_STAGE_2 - это полученная минимальная target-система, т.е _STAGE_01/st1_sysroot
## Исключительно для удобства-наглядности я пренес st1_sysroot в /_STAGE_2
##(можно этого и не делать, но знать что подразумевается /_STAGE_2 = _STAGE_01/st1_sysroot,
## точно также как подразумевается reSlackware = /_STAGE_01 )
##
## До "погружения" в chroot _STAGE_2 и исполнения 2b_st2, нужно иметь ветку исходников
## cd _STAGE_2/_mk_st2
## . ./get_tarballs
## ветка Slackware c исходниками скачивается в _STAGE_2/_mk_st2/source
## Далее смотрим текст скрипта _STAGE_2/_mk_st2/2b_st2:
## если в начале строки один "#", то строка "исполняемая" и предназначена для "раскомментирования;
## если два "##"  или больше, то это комментарии, их не трогать.
## Далее проходим _STAGE_2, что бы получить по завершении пакетную базу Slackware (base)
## cd _STAGE_2
## ./in_chroot
### cd /_mk_st2
### . ./2b_st2
##
## и, если нужно, еще раз обращяемся к тексту скрипта _STAGE2_/_mk_st2/2b_st2
##
