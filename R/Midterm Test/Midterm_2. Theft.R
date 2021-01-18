library(MASS)
library(ROCR)

y=UScrime$y
#breaks=5
hist(y, breaks=2)
#train & test data setting
train_data=UScrime[1:33,]
test_data=UScrime[34:47,]

#1: ���˹߻����ɼ��� ũ��, 0: ���� �߻� ���ɼ��� ���� 
change_train=ifelse(train_data$y>1000, 1, 0)
train_data$y=change_train
train_data$y=factor(train_data$y)
change_test=ifelse(test_data$y>1000, 1, 0)
test_data$y=change_test
test_data$y=factor(test_data$y)

theft=glm(y~M.F+GDP+NW+Ed,data=train_data, family=binomial)
summary(theft)

#�������ù�
theft.forward=step(theft, direction="forward")
theft.backward=step(theft, direction="backward")
theft.both=step(theft, direction="both")

p=predict(theft.both,newdata=test_data, type="response")
p
p1=predict(theft,newdata=test_data, type="response")

#theft.both�� auc ��
pr=prediction(p, test_data$y)
prf=performance(pr, measure="tpr", x.measure="fpr")
plot(prf)
auc=performance(pr,measure="auc")
auc=auc@y.values[[1]]
auc

#theft ���� auc ��
pr1=prediction(p1, test_data$y)
prf=performance(pr1, measure="tpr", x.measure="fpr")
auc=performance(pr1,measure="auc")
auc=auc@y.values[[1]]
auc