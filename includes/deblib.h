/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deblib.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschimme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/02 00:03:45 by mschimme          #+#    #+#             */
/*   Updated: 2019/09/13 13:58:46 by mschimme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBLIB_H
# define DEBLIB_H
//# define NDEBUG																//Макрос переключения дебаггеров.
# include <stdio.h>
# include <assert.h>
#endif

#ifndef NDEBUG
char	ft_myssert(const char *func, char *file, int line, char *expr);
# define DEBst() printf("\t\033[0;31m%d\033[0m in:\t%s\n", __LINE__, __func__);
# define DEBend() printf("\n");
# define DEBit(name, x) printf("\033[1;35m%s\033[0m == %p ", (name), (x));
# define DEBintt(name, x) printf("\033[1;35m%s\033[0m == %d ", (name), (x));
# define DEBlt(name, x) printf("\033[1;35m%s\033[0m == %zu ", (name), (x));
# define DEBtextt(name, x) printf("[\033[1;35m%s\033[0m] == [%s] ", (name), (x));
# define DEBchart(name, x) printf("[\033[1;35m%s\033[0m] == [%c] ", (name), (x));
# define DEBmesst(name) printf("\033[1;36m%s\033[0m ", (name));
# define DEBfunc() printf("\033[0;31m%d\033[0m \033[0;33mEntering\033[0m MY:\t\033[0;33m%s\033[0m of file \"%s\"\n", __LINE__, __func__, __FILE__);
# define DEB() printf("\t\033[0;31m%d\033[0m in:\t%s\n", __LINE__, __func__);
# define DEBex(name) printf("\033[0;32mExiting \033[0m MY:\t\033[0;32m%s\033[0m,%s\n\n", __func__, (name));
# define DEBprog() printf("\n\nENTRANCE IN \033[0;33m~~~~~~~~~~~~~~~~%s~~~~~~~~~~~~~~~~\033[0m\n", __FILE__);
# define DEBm() printf("Malloc failed at line \033[0;31m%d\033[0m in function: %s\n", __LINE__, __func__);
# define DEBi(name, x) printf("\033[0;31m%d\033[0m str in func: %s, \"\033[1;35m%s\033[0m\" adress %p\n", __LINE__, __func__, (name), (x));
# define DEBis(x) printf("\033[0;31m%d\033[0m str in func: %s, adress \"\033[1;35m%p\033[0m\"\n", __LINE__, __func__, (x));
# define DEBtext(name, x) printf("\033[0;31m%d\033[0m str in func: %s, arr:[%s] == [%s]\n", __LINE__, __func__, (name), (x));
# define DEBpar(name, x) printf("\033[0;31m%d\033[0m str in func: %s, arr:[%s]:\n[\n%s\n]\n", __LINE__, __func__, (name), (x));
# define DEBl(name, x) printf("\033[0;31m%d\033[0m str in func: %s, %s == %zu\n", __LINE__, __func__, (name), (x));
# define DEBint(name, x) printf("\033[0;31m%d\033[0m str in func: %s, %s == %d\n", __LINE__, __func__, (name), (x));
#define m_assert(e) (__builtin_expect(!(e), 0) ? ft_myssert(__func__, __FILE__, __LINE__, #e) : 0)

# define DEBif(x) if (!(m_assert(x)))
#endif

#ifdef NDEBUG
# define DEBst() {}
# define DEBend() {}
# define DEBit(name, x) {}
# define DEBintt(name, x) {}
# define DEBlt(name, x) {}
# define DEBtextt(name, x) {}
# define DEBchart(name, x) {}
# define DEBmesst(name) {}
# define DEBfunc() {}
# define DEB() {}
# define DEBex(name) {}
# define DEBprog() {}
# define DEBm() {}
# define DEBi(name, x) {}
# define DEBis(x) {}
# define DEBtext(name, x) {}
# define DEBpar(name, x) {}
# define DEBl(name, x) {}
# define DEBint(name, x) {}
# define DEBif(x) if(x)
#endif

