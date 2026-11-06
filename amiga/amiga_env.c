/* getenv() for Don Ceferino Hazaña on AmigaOS (-Wl,--wrap=getenv), from the
 * Team's GNU Robbo, Heroes and Berusky ports. Ceferino keeps its scores,
 * settings and saved game in $HOME (.ceferinomarcas and the others); here
 * $HOME is the drawer's user/ (made at the first start). Every other name
 * is libnix's getenv's.
 * The AmiCradle Team. GPL 2 or later, like Ceferino. */
#include <string.h>
#include <sys/stat.h>

char *__real_getenv(const char *name);

char *__wrap_getenv(const char *name)
{
	static int made;
	if (name && strcmp(name, "HOME") == 0) {
		if (!made) {
			mkdir("PROGDIR:user", 0755);
			made = 1;
		}
		return "PROGDIR:user";
	}
	return __real_getenv(name);
}
