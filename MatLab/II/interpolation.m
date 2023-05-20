function [yi] = interpolation(x, y, xi)
% ������� ������������ �� �������� ��������
% x: ���� ������������
% y: �������� ������� � ����� ������������
% xi: �����, � ������� ����� ��������� �������� ����������������� �������

n = length(x); % ���������� ����� ������������
m = length(xi); % ���������� �����, � ������� ����� ��������� �������� ����������������� �������

% �������� ������������ ������� ������
if n ~= length(y)
    error('������� ������ ������ ���� ���������� �����')
end

% �������� ������� ���������� ��������� � x
if length(unique(x)) ~= n
    error('���� ������������ ������ ���� �����������')
end


 
% ������������� ������� �������� ����������������� �������
 yi = zeros(1, m);


% ���� �� ���� ������ xi
for k = 1:m
    % ������������� �������� ��������� ��������
    li = ones(1,n);
   
    % ���� �� ���� ����� ������������
    for i = 1:n
        % ���� �� ���� ����� ������������ ����� i-��
        for j = 1:n
          if i ~= j
              % ���������� i-�� ��������� �������� ��������
             li(i) = li(i) .* (xi(k) - x(j)) / (x(i) - x(j));
          end
        end
    end

    
    % ���������� �������� ����������������� ������� � ����� xi(k)
   sum = 0;
    for i = 1:n
      sum = sum + y(i) * li(i);
    end
    yi(1,k) = sum;
    
end
% ���������� ������� yi
end