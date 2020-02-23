/*
 * expand(): expands short record like 'a-z' in string 's1' in full list
 * 'abc...xyz' in string s2. Letters in any register, numbers and records
 * like 'a-b-c', 'a-z0-9' and '-a-z' consider too.
 */

void expand(char s1[], char s2[]);

void expand(char s1[], char s2[])
{     

    int i1; /* count for 's1' */
    int saver1, saver2; /* savers for letters in 's1' for 's2' */
    int j1; /* count for 's2' */
    int last_char = -1; /* saver for last used character */

    for (i1 = 0, j1 = 0; s1[i1] != '\0'; ++i1)
        if (s1[i1] == '-' && i1 != 0 && s1[i1 + 1] != '\0') {
            saver1 = s1[i1 - 1], saver2 = s1[i1 + 1];

            last_char = (last_char == saver1) ? 1 : 0 ;
            if (last_char) {
                --j1;
                last_char = 0;
            }

            for (; saver1 <= saver2; ++j1)
                s2[j1] = saver1++;
            last_char = --saver1;
            s2[j1] = '\0';
        }
}