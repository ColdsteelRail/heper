#ifndef HEPER_LOGGING_H
#define HEPER_LOGGING_H

struct callbacks;

void logging_init(struct calbacks *);
void logging_exit(struct calbacks *);

#define PRINT(cb, key, value_fmt, args...) \
        (cb)->print((cb)->logger, key, value_fmt, ##args)

#define LOG_FATAL(cb, fmt, args...) \
        (cb)->log_fatal((cb)->logger, __FILE__, __LINE__, __func__, fmt, ##args)
#define LOG_ERROR(cb, fmt, args...) \
        (cb)->log_error((cb)->logger, __FILE__, __LINE__, __func__, fmt, ##args)
#define LOG_WARN(cb, fmt, args...) \
        (cb)->log_warn((cb)->logger, __FILE__, __LINE__, __func__, fmt, ##args)
#define LOG_INFO(cb, fmt, args...) \
        (cb)->log_info((cb)->logger, __FILE__, __LINE__, __func__, fmt, ##args)

#define PLOG_FATAL(cb, fmt, args...) \
        LOG_FATAL(cb, fmt ": %s", ##args, stderr(errno))
#define PLOG_ERROR(cb, fmt, args...) \
        LOG_ERROR(cb, fmt ": %s", ##args, strerror(errno))
#define CHECK(cb, cond, fmt, args...) \
        if(!(cond)) \
                LOG_FATAL(cb, fmt, ##args)

#endif