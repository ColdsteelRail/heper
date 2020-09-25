#ifndef HEPER_NUMLIST_H
#define HEPER_NUMLIST_H

// ptrdiff_t : 是两个指针相减的结果的无符号整数类型。
// size_t    : 是sizeof操作符的结构的无符号类型。
// wchar_t   : 是一个整数类型，它范围内的值可以表示最大扩展字符集中所有成员的不同编码值
#include <stddef.h>

struct callbacks;
struct numlist;

struct numlist *numlist_create(struct callbacks *cb);
void numlist_destroy(struct numlist *lst);
void numlist_add(struct numlist *lst, double val);
/**
 * The numbers in @tail are all moved to @lst.
 * @tail will become empty after this operation.
 */
void numlist_concat(struct numlist *lst, struct numlist *tail);
size_t numlist_size(struct numlist *lst);
double numlist_min(struct numlist *lst);
double numlist_max(struct numlist *lst);
double numlist_mean(struct numlist *lst);
double numlist_stddev(struct numlist *lst);
/*
 * sort all double in memblock of @lst,
 * then return the bouble at position
 *  @percentil / 100
 */
double numlist_percentiles(struct numlist *lst, int percentile);
#endif
