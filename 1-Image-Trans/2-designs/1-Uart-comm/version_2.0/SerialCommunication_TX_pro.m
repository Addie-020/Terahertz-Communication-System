% Uart Transmit Data

% Input image and transform it into gray image 
image_rgb = imread('lena.jpg');
image_gray = rgb2gray(image_rgb);           % transform rgb to gray
% image_gray_1 = imresize(image_gray,[32 32]);
imshow(image_gray);

% Read height and width of the image and serialize image data
image_gray_T = image_gray;
[image_h, image_w] = size(image_gray_T);    % record the height and width of image
image_data = reshape(image_gray_T, 1, image_h.*image_w);

% Start with 0, COM sends h and w after 0, then sends DATA...
image_send = [0, uint16(image_h), uint16(image_w), image_data];

input("按回车发送...");

% Open the serial port and send data...
Ports = serialportlist;     % check the avaliable ports
com_name = Ports(1);     % change the COM if it is necessary
BROUDRATE = 9600;      % set the broudrate

s = serialport(com_name, BROUDRATE);    % open and connect the serialport
write(s, image_send, "uint16");         % send data of image
disp("ok...");                     % display the state
% feedback = read(s, 1, "uint8");         % wait for the feedback and
% display if feedback == 0
%     disp("SUCCESS!");
% elseif feedback == 1
%     disp("ERROR!");
% end
