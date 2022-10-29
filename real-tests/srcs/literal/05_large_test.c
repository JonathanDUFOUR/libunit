/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05_large_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 20:25:52 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/09 21:53:52 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "unit.h"
#include "ft_printf.h"

#ifdef TEST
# undef TEST
#endif
#define TEST "\
koala tutu tata 42 42 pouic 42 bar bar 42 tata 42 42 muf koala koala tata 42 42\
 42 pouic tutu 42 x koala lol koala x koala mdr foo bar koala bar koala 42 x tu\
tu tata x tata x pouic tata x pouic pouic muf tutu lol x x muf 42 tata muf tutu\
 mdr x x tutu 42 x lol x x pouic muf tutu 42 koala mdr 42 koala koala x foo 42 \
x x koala foo x koala x tata 42 x pouic mdr koala tata tata 42 x lol 42 tata 42\
 koala mdr pouic mdr koala tata bar x pouic tutu tata tutu tutu foo x 42 42 koa\
la tata 42 pouic x koala x koala x tata x x lol koala x tutu koala lol x bar mu\
f 42 tata foo tata x lol koala 42 x muf koala pouic koala 42 koala 42 tata tata\
 bar 42 lol x koala 42 koala x foo 42 mdr 42 x pouic tutu 42 42 foo pouic muf x\
 x pouic 42 tata x tata koala x muf pouic tata lol 42 koala 42 tata muf x x pou\
ic 42 tutu mdr mdr pouic pouic 42 koala 42 muf koala tata pouic tutu pouic x 42\
 pouic x x mdr 42 tata x 42 pouic x tata pouic lol x tata bar 42 42 x tata x ko\
ala lol tata koala koala x 42 tata muf pouic 42 x pouic pouic pouic lol x x x x\
 42 pouic lol foo tata tata 42 x tutu 42 koala x pouic tata muf 42 tata tutu ta\
ta tata koala tutu 42 foo muf 42 tata pouic pouic pouic muf koala 42 pouic x md\
r x 42 tutu tutu tata tata mdr tata 42 muf tata 42 tutu x bar pouic lol 42 x mu\
f tata koala 42 bar x lol x 42 tata koala x mdr 42 pouic tutu x x koala foo tat\
a koala lol x pouic tutu tutu koala x pouic tata x x mdr mdr bar 42 x foo x tat\
a tutu pouic koala 42 foo bar 42 tata lol tutu koala koala muf x 42 tata x 42 x\
 42 x x lol 42 foo tata tata koala mdr tata muf mdr tutu x x x tata lol tutu ta\
ta bar x 42 x muf koala muf 42 pouic pouic x pouic x x pouic tata 42 42 42 tata\
 lol x tata x koala 42 42 muf x 42 mdr tutu mdr koala lol pouic x x koala tutu \
mdr koala bar pouic x koala 42 42 42 42 lol x tutu tata tata koala mdr lol 42 m\
uf tata koala x koala lol pouic mdr koala 42 koala x 42 x tata bar tutu 42 foo \
koala x mdr x x foo pouic 42 koala x tutu pouic koala pouic tata pouic foo tata\
 x tutu x tutu tutu koala 42 42 tata x foo x koala mdr x x 42 pouic x x 42 42 b\
ar 42 x x x tata 42 koala tutu tata mdr koala tutu tutu tutu 42 koala x koala k\
oala bar tutu x koala 42 42 x mdr koala tutu koala tutu muf x 42 muf pouic koal\
a lol 42 x x 42 42 42 tata muf 42 42 x mdr tutu bar 42 bar mdr 42 lol tata tutu\
 x 42 tata 42 muf 42 x x x 42 42 pouic pouic bar 42 tata x 42 42 koala tutu lol\
 tutu muf koala tata 42 bar mdr 42 42 koala tata tata 42 42 x mdr pouic muf 42 \
x koala muf mdr koala x koala pouic 42 tata pouic koala koala pouic 42 42 x 42 \
42 koala foo 42 bar koala x x x pouic muf x x koala pouic tata 42 tata foo x tu\
tu muf 42 pouic pouic pouic tata koala 42 42 tutu lol x tata tata 42 muf muf ba\
r 42 x x koala lol muf bar koala foo muf x tata x 42 x pouic bar 42 x tutu tata\
 lol x x 42 muf 42 muf tutu x tutu pouic 42 foo tutu x tata 42 koala x pouic x \
x x x muf koala 42 42 tata lol lol koala tata koala x foo x x 42 tata 42 tata m\
dr tata tata tata tata 42 tata koala 42 42 tata foo bar 42 42 tutu koala 42 koa\
la x tutu tata 42 mdr x x x lol 42 x pouic tutu mdr tata x tutu pouic bar x 42 \
x tutu tutu bar muf foo tutu koala muf tutu koala tata 42 x muf 42 foo muf foo \
mdr pouic lol 42 muf muf tutu tutu x koala tata 42 tata tutu tutu koala lol koa\
la x x tutu x muf x tutu mdr x x muf tata 42 tata x 42 bar foo 42 koala tata po\
uic tutu lol x 42 42 42 42 koala 42 42 tutu tata muf x 42 tata x x 42 42 x mdr \
42 pouic pouic pouic tata pouic x foo tutu 42 tata foo 42 42 42 x 42 tata lol x\
 x pouic tutu 42 x tata bar foo muf x tata tata tutu x tata koala 42 x x koala \
42 pouic 42 lol mdr tata 42 koala x lol 42 koala 42 tutu tata koala x tutu lol \
tata 42 tutu x tata tata mdr 42 42 tutu x x x muf tata x foo x tata tutu koala \
pouic 42 mdr pouic 42 x pouic pouic 42 tutu 42 tata tata x tutu x pouic foo pou\
ic tata x koala lol tata pouic x x x bar pouic tutu pouic koala pouic x 42 poui\
c muf bar 42 x 42 mdr tata tata pouic koala x pouic mdr 42 42 42 lol mdr koala \
x bar pouic 42 x koala foo tata x muf x 42 pouic koala pouic 42 tata tata 42 fo\
o tutu tata x pouic 42 x x x pouic tutu bar x lol x x muf x 42 pouic koala lol \
42 x tata x x tata tutu lol tata bar tutu koala x koala tutu 42 bar x tutu koal\
a tata x 42 tata bar tata x pouic tutu 42 koala tutu pouic 42 42 42 42 x 42 pou\
ic tutu 42 tutu foo 42 x 42 x tutu koala pouic foo 42 42 lol tutu x 42 foo lol \
bar lol koala mdr muf 42 42 pouic x tata tata x pouic koala x pouic x pouic 42 \
tutu 42 koala x x 42 foo tutu 42 tata koala tata 42 koala koala x tutu bar tata\
 foo lol foo 42 x 42 tata tata 42 bar mdr koala pouic foo pouic mdr x koala foo\
 koala 42 tutu tutu x 42 tutu koala koala x 42 muf x x x tata pouic x x 42 42 4\
2 x pouic x pouic koala tata muf bar tutu mdr tutu lol muf tata mdr muf 42 poui\
c koala 42 x 42 x koala mdr x 42 muf foo pouic bar 42 x pouic pouic 42 x tata p\
ouic tata tutu x mdr tata mdr koala 42 tutu koala 42 koala 42 x pouic x pouic f\
oo x lol pouic x muf koala lol tata x 42 pouic pouic x foo 42 foo koala koala m\
dr foo muf tata koala pouic 42 x foo x 42 42 42 42 42 42 42 42 koala lol koala \
tutu tata 42 foo x 42 tata x tutu tutu tutu mdr pouic x x 42 foo koala tata pou\
ic 42 x pouic koala tata pouic 42 koala 42 x muf 42 pouic bar x tata 42 x x x k\
oala tata pouic koala x muf muf x tata x tata koala 42 tutu koala pouic 42 poui\
c koala 42 pouic tata koala tutu koala bar mdr tata 42 lol bar x bar tutu bar t\
utu x mdr tata tutu muf x foo 42 x x 42 lol foo tutu x pouic x mdr 42 pouic x 4\
2 muf mdr koala 42 x bar 42 koala pouic koala pouic 42 tata 42 42 tutu muf foo \
x tutu bar muf x x koala 42 bar x koala tata tutu 42 muf 42 koala foo koala 42 \
muf tutu koala 42 koala 42 foo 42 x x foo foo foo pouic muf pouic tutu tutu x t\
ata tata koala 42 tutu 42 42 42 foo 42 pouic pouic koala koala foo koala koala \
x x tata lol koala 42 x muf koala 42 bar tata lol koala 42 x x koala koala x ta\
ta 42 muf 42 pouic pouic koala x pouic muf x koala muf 42 foo lol x 42 pouic x \
pouic 42 tutu koala tata 42 lol 42 x tata x x 42 pouic bar x 42 42 tata x muf 4\
2 x pouic tata x x 42 x x x tata 42 x pouic 42 tutu x mdr 42 pouic foo x koala \
tutu 42 42 mdr 42 tata x tutu pouic 42 x mdr x lol 42 lol pouic x x foo lol tut\
u 42 foo lol x bar pouic tata koala muf 42 koala koala 42 lol tutu koala tata 4\
2 koala tutu bar 42 42 tutu tutu tata pouic x tata x 42 tutu x x pouic pouic ba\
r x x foo 42 x 42 pouic mdr tata 42 42 x tutu 42 x x koala 42 tutu tata lol koa\
la 42 x koala x x x 42 tutu lol koala lol x tutu koala lol tata tutu lol bar md\
r muf x 42 pouic x pouic tata foo tata x tutu mdr x koala pouic 42 42 koala x l\
ol koala pouic koala x muf tata koala x 42 x muf koala tutu 42 koala tata lol t\
ata 42 tata koala 42 tata koala koala pouic x x 42 lol 42 42 koala pouic 42 42 \
tutu x tata x lol 42 muf tutu koala pouic 42 tutu bar tutu pouic bar pouic tata\
 x 42 tutu lol tutu 42 42 tutu koala tutu 42 koala tutu mdr tata tutu tata poui\
c 42 pouic 42 mdr lol pouic tutu mdr 42 42 tutu x x muf 42 pouic muf x x pouic \
mdr koala tata foo koala mdr 42 x pouic 42 42 42 x x x tata 42 42 x tata 42 x b\
ar foo lol pouic tata 42 x tata koala pouic tata 42 tutu tata lol x tata bar ta\
ta tutu 42 42 42 pouic foo x pouic 42 tata koala x koala pouic mdr x mdr muf tu\
tu mdr tutu x pouic tata koala lol tutu pouic koala tutu pouic tata pouic bar x\
 pouic x tutu tata bar foo koala muf muf 42 42 42 lol foo x x tutu mdr 42 tutu \
pouic 42 x muf tata tata x koala koala x 42 x bar tata x 42 x tata x 42 foo 42 \
tata bar tata tutu lol pouic koala x x koala pouic x 42 tata x lol 42 lol koala\
 muf pouic muf x tata koala pouic tata pouic tata lol 42 x 42 x 42 x x 42 koala\
 pouic x tata lol muf x tutu x tutu tutu x x pouic x koala 42 foo pouic koala f\
oo 42 lol x 42 42 bar tata muf koala tutu 42 koala tata muf tutu 42 42 foo muf \
x koala x x 42 pouic x tata bar pouic mdr muf koala muf x 42 x tutu 42 bar mdr \
tata tata tutu 42 tata 42 42 tata 42 lol koala tata mdr x 42 x 42 x muf x 42 x \
42 tutu 42 bar x bar 42 tutu 42 x x x 42 pouic tutu bar 42 koala foo bar 42 42 \
tata tata 42 muf tata pouic koala mdr 42 tata 42 pouic tutu tata pouic x koala \
x koala mdr 42 42 42 42 pouic koala koala tata tutu tata x 42 pouic 42 tata x f\
oo 42 mdr x tata 42 pouic x x pouic koala koala 42 42 foo x x bar x x foo tutu \
x pouic foo tata 42 lol x 42 koala 42 pouic 42 42 tutu tata x foo 42 mdr koala \
pouic 42 x 42 tutu pouic x koala pouic x tata 42 tutu tutu koala muf 42 pouic p\
ouic tata mdr tata 42 pouic koala x 42 pouic tutu bar 42 lol 42 tata pouic tata\
 koala 42 lol 42 42 x mdr x tutu x 42 lol 42 tata 42 koala tutu tutu x koala ko\
ala muf tata 42 koala x bar tutu foo koala 42 x x 42 pouic x pouic bar tutu x t\
ata tata tata lol pouic x tutu 42 42 x x 42 koala 42 koala koala koala 42 tata \
mdr x pouic tutu tata x 42 x 42 42 bar bar bar 42 koala x 42 pouic x tutu x x l\
ol pouic tata pouic bar x 42 lol tata 42 muf tutu muf x pouic pouic tutu mdr x \
mdr x 42 tutu x tutu pouic mdr foo muf 42 42 foo x x bar lol 42 tutu 42 42 tata\
 bar 42 x koala koala 42 pouic pouic koala 42 tutu mdr koala x x mdr lol tata 4\
2 tata pouic x mdr muf pouic muf mdr mdr koala koala koala x koala lol tutu bar\
 tutu tutu x x bar x tata x tutu 42 42 bar foo tutu pouic koala koala 42 tata 4\
2 tutu pouic foo koala x 42 tata 42 mdr muf tata tata tata 42 x koala tata tutu\
 bar x koala 42 pouic x tata 42 foo tutu tata muf x pouic bar tutu koala foo x \
42 x pouic 42 tata pouic 42 lol tata pouic x x tata x pouic x bar 42 mdr x foo \
koala 42 x lol tutu pouic x pouic x tata x foo x bar koala tata koala tutu bar \
muf 42 x foo pouic bar bar x x mdr bar koala tutu pouic bar tutu mdr koala tata\
 pouic tutu 42 x tata pouic 42 x muf x 42 x koala x muf koala muf 42 x tutu x p\
ouic 42 42 pouic pouic x 42 42 lol foo tata 42 x muf mdr tata foo lol muf tutu \
x koala x 42 x tata x pouic x tutu foo x mdr x koala pouic mdr pouic 42 koala t\
ata koala tata tata foo tutu foo foo x tutu x 42 tutu pouic 42 koala muf x koal\
a tata 42 42 tata tata koala x 42 42 pouic koala x tata 42 x x 42 bar x mdr tat\
a x tata 42 tata mdr koala lol muf x tata bar 42 pouic koala tata tata tutu pou\
ic mdr foo tutu tata tutu x 42 koala tutu x 42 tata koala x 42 pouic x pouic tu\
tu tata pouic tata pouic koala 42 koala tata 42 42 mdr pouic x 42 lol lol koala\
 x koala tata 42 bar 42 x x 42 foo 42 lol mdr x 42 x x tutu tata bar pouic x po\
uic koala x tata tata lol pouic foo x bar lol x 42 bar x tata x lol 42 foo tutu\
 pouic foo 42 x 42 x tata 42 tata x tata 42 x lol x tata tutu mdr muf 42 tata p\
ouic tata x pouic tutu mdr 42 tutu muf 42 x x x x 42 koala tutu tata pouic tata\
 x x x pouic koala 42 bar 42 bar 42 pouic x tata 42 42 koala pouic foo x x x x \
koala pouic x 42 tata x pouic x foo mdr tata x tata pouic tutu x mdr x koala ta\
ta 42 tata 42 tutu pouic koala 42 lol 42 x pouic tutu lol foo tata 42 mdr muf l\
ol tutu muf pouic tata x koala mdr tata tata lol pouic bar 42 42 koala x tutu m\
dr 42 x 42 koala koala mdr x pouic 42 tata koala tata tata muf 42 mdr x tutu tu\
tu koala bar tutu tata 42 koala x koala tutu 42 lol foo koala koala koala x x p\
ouic lol pouic lol tata x koala x 42 42 tata tutu x 42 x 42 foo 42 muf 42 bar t\
utu x x muf bar lol bar x 42 tutu tata 42 42 x koala bar bar x tata koala 42 md\
r 42 x 42 pouic bar koala pouic 42 muf foo mdr x tutu lol 42 pouic pouic 42 tat\
a x x tutu tata tata 42 42 x 42 tata pouic 42 tata tutu foo x tata tutu x foo p\
ouic lol x pouic x pouic koala tutu foo mdr koala 42 pouic 42 muf 42 lol pouic \
42 tata tutu x mdr tata bar x 42 pouic tata lol x pouic muf mdr tata tutu x mdr\
 pouic x pouic tata koala mdr 42 42 lol 42 x 42 tutu tutu pouic koala foo tata \
muf tutu bar muf pouic 42 42 koala 42 mdr 42 bar pouic tata x 42 42 muf pouic t\
ata 42 mdr x tutu tata pouic x pouic mdr x tutu 42 x tata tata pouic tutu 42 x \
tata 42 koala 42 x x muf tutu muf x pouic koala x tata tata muf tutu tutu koala\
 tutu x 42 tutu x x x 42 tutu pouic 42 koala bar 42 lol x 42 tutu mdr tata lol \
42 x 42 x koala 42 lol x tutu x tata tata x lol foo 42 42 x 42 pouic x x muf po\
uic tata 42 foo mdr pouic x 42 mdr 42 42 tata muf koala tutu bar x muf 42 x 42 \
tutu foo tata 42 mdr x pouic koala koala foo koala muf tata muf tutu 42 tata x \
muf mdr pouic muf koala muf x pouic koala mdr 42 mdr pouic tata tutu x tutu koa\
la 42 tata bar tata tutu x tata tutu 42 42 foo pouic tutu x tata bar x mdr koal\
a tata x muf tata x x pouic 42 42 x pouic tutu 42 koala x tata tata pouic koala\
 42 muf 42 tutu mdr x tutu muf lol tata x pouic koala 42 x x x pouic 42 muf bar\
 tata tata foo x koala pouic koala tutu tata x 42 tata pouic foo x pouic x 42 x\
 tutu 42 lol pouic tata tutu x x 42 x 42 bar tata 42 x koala 42 koala x tata fo\
o tutu mdr koala tutu tutu pouic tutu x x koala x pouic x 42 muf 42 tutu bar ta\
ta 42 koala 42 42 koala tata koala x 42 tata koala tutu tutu 42 tutu x tata 42 \
tutu tata foo tata koala koala x foo pouic bar x x tutu pouic 42 x 42 koala pou\
ic pouic pouic foo mdr koala tutu tata x 42 muf pouic foo x foo pouic 42 tata k\
oala x lol lol pouic tata x koala x tutu 42 42 42 tutu 42 bar pouic tata x tutu\
 x x pouic koala 42 42 koala x tata 42 pouic pouic tutu tata foo pouic x pouic \
lol x x 42 42 mdr tata mdr koala pouic 42 tata 42 foo pouic tutu tata x pouic x\
 tata 42 x tata mdr tutu koala x 42 tata muf x koala 42 muf 42 tata koala x koa\
la tata tata tata pouic x x tutu 42 x x tata x foo 42 x 42 42 x koala lol pouic\
 tata x lol x koala x tata x 42 tutu tutu lol tutu koala mdr bar pouic tutu koa\
la 42 tutu x 42 x lol tutu foo x x tata tutu 42 foo x tata koala x x x 42 mdr x\
 bar mdr 42 tata foo tutu pouic tutu mdr 42 42 42 tutu tutu x x bar koala lol t\
utu 42 42 tutu 42 x bar 42 x 42 foo tata 42 pouic muf tutu x 42 pouic pouic koa\
la x tata x foo pouic lol pouic tata pouic pouic pouic x bar pouic koala tata t\
utu lol lol 42 mdr pouic bar foo koala lol 42 tutu 42 foo x foo koala 42 lol x \
42 x tata 42 muf x koala koala mdr koala 42 42 x koala koala tata tutu x 42 tat\
a 42 tutu x pouic koala tutu tata x x tata koala pouic x 42 x 42 42 x 42 tata p\
ouic x pouic tutu tutu 42 tata pouic koala x tata koala koala pouic tutu tutu t\
ata tutu bar pouic tata muf foo x tata pouic tutu bar koala tutu 42 42 pouic ba\
r tutu pouic tata 42 pouic 42 tutu x mdr koala tutu x x tutu x pouic tutu koala\
 pouic koala 42 mdr tutu tutu pouic koala tata tata tutu 42 pouic tata bar poui\
c lol pouic 42 koala x tutu 42 42 bar tutu koala x 42 42 tata lol tutu x pouic \
pouic pouic 42 mdr pouic 42 tutu tata 42 42 x pouic tutu x 42 pouic tutu 42 42 \
42 bar x x tutu x lol bar lol bar tata tutu tata tata tata koala tata tutu x ko\
ala tutu 42 pouic x tata muf pouic tutu tata 42 42 koala tutu x x 42 x mdr tata\
 koala tata bar 42 foo x x tutu tutu 42 x koala tata 42 x 42 koala muf tata 42 \
42 42 mdr x tata lol muf pouic pouic koala lol foo 42 lol tata tutu tutu x x ko\
ala x 42 42 bar tata x pouic koala foo tata koala mdr koala x tata lol x x tata\
 tutu muf foo x pouic pouic tutu bar pouic tutu tutu tutu tutu 42 tutu 42 tutu \
lol 42 tutu pouic x pouic tata 42 x 42 bar tutu x x x 42 tata 42 muf tutu pouic\
 tata mdr tutu pouic tutu 42 42 x pouic x lol 42 pouic koala koala 42 tutu tata\
 bar 42 x pouic foo tutu koala bar x tata pouic x x pouic 42 x x tata bar mdr t\
utu koala pouic mdr 42 42 foo tata pouic tata tutu tata 42 tata x koala koala t\
utu 42 x muf tata muf pouic tutu pouic x foo bar bar muf foo koala bar x muf lo\
l koala pouic tutu x 42 tata tata pouic koala 42 tata 42 42 42 muf koala tutu k\
oala x foo 42 42 lol foo lol koala koala koala bar koala x pouic tutu tutu poui\
c pouic bar x x mdr pouic tata mdr x 42 x tata 42 mdr foo muf koala tata 42 x p\
ouic koala 42 42 mdr tata muf 42 muf x 42 pouic x tutu lol foo 42 x muf 42 mdr \
pouic tata lol x 42 42 koala x x x 42 x tata mdr 42 tata tata pouic x x x 42 ta\
ta x x muf pouic bar koala tutu x x foo mdr tata tutu 42 pouic pouic x koala x \
42 lol tata koala x koala tata pouic 42 42 x koala tutu mdr tutu pouic 42 42 x \
x foo lol x tata mdr x tutu x x tata x pouic 42 x tutu koala pouic x x muf poui\
c koala lol mdr tutu x mdr pouic lol 42 muf x bar mdr mdr pouic mdr foo pouic b\
ar koala pouic pouic 42 42 tutu lol pouic foo 42 42 pouic koala tata lol pouic \
x mdr tutu foo tata 42 lol koala pouic bar foo mdr bar koala koala tata tutu ta\
ta koala 42 mdr 42 x mdr x tutu lol koala koala tutu koala tutu 42 pouic pouic \
42 x x x tutu 42 tutu tata bar lol x 42 tata muf muf x tata x pouic x 42 x koal\
a tutu x tutu 42 tutu koala foo bar tutu x 42 foo koala mdr pouic x bar 42 x x \
mdr x muf tata koala bar x koa"

typedef struct s_data	t_data;

struct s_data
{
	char		buff[4097];
	char		*str0;
	char		*str1;
	void		*ent;
	int			ret0;
	int			ret1;
	size_t		len;
	ssize_t		rd;
};

int	literal_large_test(void)
{
	t_data	d;
	int		cmp;

	memset(&d, 0, sizeof(t_data));
	if (redirect_init())
		return (EXIT_FAILURE);
	d.ret0 = printf(TEST);
	fflush(stdout);
	if (d.ret0 > 0)
		d.rd = read(STDIN_FILENO, d.buff, 4096);
	while (d.rd)
	{
		if (d.str0)
			d.len = strlen(d.str0);
		else
			d.len = 0;
		d.buff[d.rd] = 0;
		d.ent = (void *)d.str0;
		d.str0 = calloc((d.len + strlen(d.buff) + 1), sizeof(char));
		if (!d.str0)
		{
			free(d.ent);
			return (EXIT_FAILURE);
		}
		if (d.len)
			strcpy(d.str0, d.ent);
		free(d.ent);
		strcat(d.str0, d.buff);
		if (d.rd == 4096)
			d.rd = read(STDIN_FILENO, d.buff, 4096);
		else
			d.rd = 0;
	}
	d.ret1 = ft_printf(TEST);
	if (d.ret1 > 0)
		d.rd = read(STDIN_FILENO, d.buff, 4096);
	while (d.rd)
	{
		if (d.str1)
			d.len = strlen(d.str1);
		else
			d.len = 0;
		d.buff[d.rd] = 0;
		d.ent = (void *)d.str1;
		d.str1 = calloc((d.len + strlen(d.buff) + 1), sizeof(char));
		if (!d.str1)
		{
			free(d.ent);
			return (EXIT_FAILURE);
		}
		if (d.len)
			strcpy(d.str1, d.ent);
		free(d.ent);
		strcat(d.str1, d.buff);
		if (d.rd == 4096)
			d.rd = read(STDIN_FILENO, d.buff, 4096);
		else
			d.rd = 0;
	}
	if (d.ret0 > 0 && d.ret1 > 0)
		cmp = strcmp(d.str0, d.str1);
	else
		cmp = 0;
	free(d.str0);
	free(d.str1);
	if (redirect_end())
		return (EXIT_FAILURE);
	if (!cmp && d.ret0 == d.ret1)
		return (0);
	else
		return (-1);
}
