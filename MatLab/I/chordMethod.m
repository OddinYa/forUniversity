% ������� ��� ������� ��������� ������� ����
% ������� ���������: ������������ a, b, c � d ��������� at^3 + bt^2 + ct - d 
% �������� ���������: ��������� ������ � ����� ��������
function [root, iter] = chordMethod(a, b, c, d)

eps = 0.0006;                   % ��������
max_iter = 100;                % ������������ ����� ��������

% ���������� �������, ������� ����� ������, � ��������� �����������
f = @(t) a*t^3 + b*t^2 + c*t - d;
t0 = -d / c;
t1 = t0 + eps;

iter = 0;
while iter < max_iter                                    % �������� ������������ �������
    iter = iter + 1;
    
    t_next = t1 - f(t1)*(t1 - t0) / (f(t1) - f(t0));     % ��������� ��������� �����������
    
    if abs(t_next - t1) < eps                           % ��������� ���������� �������� ��������
        root = t_next;
        break;
    end
    
    t0 = t1;
    t1 = t_next;
end

if iter == max_iter     % ���� �������� ������������� ����� ��������, ������� ��������������
    warning('���������� ������������ ���������� ��������');
end

% ������ ������ ������� � ������� �����
t = linspace(-1, 1, 1000);
y = a*t.^3 + b*t.^2 + c*t - d;
plot(t, y);
xlabel('t');
ylabel('y');
grid on;

try                                      % ���������� try-catch ���� ��� ��������� ������, ����� ������ ���
hold on;
plot(root, 0, 'ro');
root = fzero(f, [-1, 0]);           % ����� ������
plot(root, 0, 'ro');
root = fzero(f, [1, root-eps]);  % ������ ������
plot(root, 0, 'ro');
hold off;
cache exception
    disp('������ ���')
end

% ������� ����������
disp(['������ ���������: ', num2str(root)]);
disp(['����� ��������: ', num2str(iter)]);




