s = serialport("COM4",115200);
input("按回车键接收...");
flush(s);
M = 0;
N = 0;
capacity = 0;
T = read(s,1,"uint16");
if T==0
    M = read(s,1,"uint16");
    N = read(s,1,"uint16");
    capacity = M.*N;
    data = read(s,capacity,"uint16");
%     write(s,0,"uint8");
else
%     write(s,1,"uint8");
end

%图像按宽高存储写入
i=1;
for k1=1:N
    for k2=1:1:M
          image1(k1,k2)=uint16(data(i)); %这里我把原来uint8改成uint16了
          i=i+1;
    end
end
%屏幕输出部分
figure;
image2 = uint8(image1);
imshow(image2);

%保存文件输出
[name,path]=uiputfile([path 'imggray.bmp'], '保存灰度图像');
file=strcat(path,name);
imwrite(image2,file,'bmp');