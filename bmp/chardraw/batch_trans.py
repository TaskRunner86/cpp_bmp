

import os
import time
import sys

# 会有大量文件读写，仅用于学习原理，不能用于生产力，会减少硬盘寿命
def main():
    filelist = os.listdir('src')

    for item in filelist:
    	if item.endswith(".bmp"):
            os.system('CharDraw.exe src/' + item + ' dst/' + item)
            print(item + ' ok!')

if __name__ == '__main__':
	main()
