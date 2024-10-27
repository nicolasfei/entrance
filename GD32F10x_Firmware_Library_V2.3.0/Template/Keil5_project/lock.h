#ifndef LOCK_H
#define LOCK_H

/* lock init function */
void lock_init(void);

/* lock release function */
void lock_release(void);

/* lock read function */
void lock_read(void);

/* lock set function */
void lock_set(void);

#endif /* LOCK_H */