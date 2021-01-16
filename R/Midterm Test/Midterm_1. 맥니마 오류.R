library(MASS)
library(tree)
library(caret)

y=UScrime$y
#breaks=2
hist(y, breaks=2)
# 몇개의 구간으로 나눌지 확인
change_train=ifelse(UScrime$y>1000, 1, 0)
UScrime$y=change_train
UScrime$y=factor(UScrime$y)

#test data, train data 나누기
set.seed(47)
classification=createDataPartition(y=UScrime$y,p=0.7,list=FALSE)
train_data=UScrime[classification,]
test_data=UScrime[-classification,]

violent_crime=tree(y~Prob+NW+Time+Ed,data=train_data)
plot(violent_crime)
text(violent_crime)

#기준 정하기
criteria_pruning=cv.tree(violent_crime, FUN=prune.misclass)
plot(criteria_pruning)

#새로운 tree
pruning=prune.misclass(violent_crime, best=3)
plot(pruning)
text(pruning, pretty=0)
#예측값과 기존값 비교
treepred=predict(pruning, test_data, type="class")
confusionMatrix(treepred, test_data$y)
