%module Task
%{
#include "task.h"
#include <time.h>
extern bool isCheck();
extern void setCheck(bool flag);
extern bool isInquiry();
extern void setInquiry(bool flag);
extern bool isDeposit();
extern void setDeposit(bool flag);
extern bool isWithdraw();
extern void setWithdraw(bool flag);
extern void setAmount(double amt);
extern double getAmount();
%}

%include "task.h"
extern bool isCheck();
extern void setCheck(bool flag);
extern bool isInquiry();
extern void setInquiry(bool flag);
extern bool isDeposit();
extern void setDeposit(bool flag);
extern bool isWithdraw();
extern void setWithdraw(bool flag);
extern void setAmount(double amt);
extern double getAmount();
