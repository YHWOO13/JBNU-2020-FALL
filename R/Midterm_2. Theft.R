library(MASS)
library(ROCR)

y=UScrime$y
#breaks=5
hist(y, breaks=2)
#train & test data setting
train_data=UScrime[1:33,]
test_data=UScrime[34:47,]

#1: 범죄발생가능성이 크다, 0: 범죄 발생 가능성이 직다 
change_train=ifelse(train_data$y>1000, 1, 0)
train_data$y=change_train
train_data$y=factor(train_data$y)
change_test=ifelse(test_data$y>1000, 1, 0)
test_data$y=change_test
test_data$y=factor(test_data$y)

theft=glm(y~M.F+GDP+NW+Ed,data=train_data, family=binomial)
summary(theft)

#변수선택법
theft.forward=step(theft, direction="forward")
theft.backward=step(theft, direction="backward")
theft.both=step(theft, direction="both")

p=predict(theft.both,newdata=test_data, type="response")
p
p1=predict(theft,newdata=test_data, type="response")

#theft.both의 auc 값
pr=prediction(p, test_data$y)
prf=performance(pr, measure="tpr", x.measure="fpr")
plot(prf)
auc=performance(pr,measure="auc")
auc=auc@y.values[[1]]
auc

#theft 모델의 auc 값
pr1=prediction(p1, test_data$y)
prf=performance(pr1, measure="tpr", x.measure="fpr")
auc=performance(pr1,measure="auc")
auc=auc@y.values[[1]]
auc
