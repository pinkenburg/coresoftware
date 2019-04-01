#! /bin/bash
srcdir=`dirname $0`
test -z "$srcdir" && srcdir=.

#(cd $srcdir; aclocal -I ${OFFLINE_MAIN}/m4 -I ${OFFLINE_MAIN}/share/aclocal;\
#libtoolize --force; automake -a --add-missing; autoconf)

# we need to add our install dir to the m4 macro dirs in the rare case there is a new one
for arg in  "$@"
do
  if [[ $arg = *prefix* ]]
  then
    m4dir=${arg##*=}
    if [[ -d  $m4dir/m4 ]]
    then
      aclocal_incdirs="-I $m4dir/m4"
    fi
  fi
done
# here are our m4 macros, m4 dir seems the default
if [[ -d  ${OFFLINE_MAIN}/m4 ]]
then
  aclocal_incdirs="$aclocal_incdirs -I ${OFFLINE_MAIN}/m4"
fi
# this is where gsl puts its m4 macro
if [[ -d  ${OFFLINE_MAIN}/share/aclocal ]]
then
  aclocal_incdirs="$aclocal_incdirs -I ${OFFLINE_MAIN}/share/aclocal"
fi

(cd $srcdir; autoreconf -iv --warnings=all $aclocal_incdirs;)
$srcdir/configure "$@"
