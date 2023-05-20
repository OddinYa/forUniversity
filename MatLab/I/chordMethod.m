% Функция для решения уравнения методом хорд
% Входные параметры: коэффициенты a, b, c и d уравнения at^3 + bt^2 + ct - d 
% Выходные параметры: найденный корень и число итераций
function [root, iter] = chordMethod(a, b, c, d)

eps = 0.0006;                   % точность
max_iter = 100;                % максимальное число итераций

% Определяем функцию, которую будем решать, и начальные приближения
f = @(t) a*t^3 + b*t^2 + c*t - d;
t0 = -d / c;
t1 = t0 + eps;

iter = 0;
while iter < max_iter                                    % начинаем итерационный процесс
    iter = iter + 1;
    
    t_next = t1 - f(t1)*(t1 - t0) / (f(t1) - f(t0));     % вычисляем следующее приближение
    
    if abs(t_next - t1) < eps                           % проверяем достижение заданной точности
        root = t_next;
        break;
    end
    
    t0 = t1;
    t1 = t_next;
end

if iter == max_iter     % если достигли максимального числа итераций, выводим предупреждение
    warning('Достигнуто максимальное количество итераций');
end

% Строим график функции и находим корни
t = linspace(-1, 1, 1000);
y = a*t.^3 + b*t.^2 + c*t - d;
plot(t, y);
xlabel('t');
ylabel('y');
grid on;

try                                      % используем try-catch блок для обработки случая, когда корней нет
hold on;
plot(root, 0, 'ro');
root = fzero(f, [-1, 0]);           % левый корень
plot(root, 0, 'ro');
root = fzero(f, [1, root-eps]);  % правый корень
plot(root, 0, 'ro');
hold off;
cache exception
    disp('Корней нет')
end

% Выводим результаты
disp(['Корень уравнения: ', num2str(root)]);
disp(['Число итераций: ', num2str(iter)]);




