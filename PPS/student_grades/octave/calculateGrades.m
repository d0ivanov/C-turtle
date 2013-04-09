load classGrades.mat
namesAndGrades
grades = namesAndGrades(:,2:end);
meanGrades = mean(grades)
meanGrades = nanmean(grades)
meanMatrix = ones(15, 1) * meanGrades
curvedGrades = 3.5 * (grades./meanMatrix)
nanmean(curvedGrades)
curvedGrades(curvedGrades > 5) = 5;
totalGrade = nanmean(curvedGrades, 2);
totalGrade = ceil(totalGrade);
letterGrades = "FDCBA";
for i = 1:size(curvedGrades)(1)
  totalGrades(i) = letterGrades(totalGrade(i));
endfor;
disp(char(totalGrades))
