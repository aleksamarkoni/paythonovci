
import zipfile, zlib
from bs4 import BeautifulSoup
import sys

from urllib.request import Request, urlopen
from urllib.error import URLError
someurl = "http://prntscr.com/f7eluu"

headers = {
'Host': 'prnt.sc',
'Connection': 'keep-alive',
'Cache-Control': 'max-age=0',
'Upgrade-Insecure-Requests': '1',
'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/58.0.3029.110 Safari/537.36',
'Accept': 'text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,*/*;q=0.8',
'Accept-Encoding': 'gzip',
'Accept-Language': 'en-US,en;q=0.8,bs;q=0.6,sr;q=0.4',
}
req = Request(someurl, headers = headers)
try:
    response = urlopen(req)
except URLError as e:
    if hasattr(e, 'reason'):
        print('We failed to reach a server.')
        print('Reason: ', e.reason)
    elif hasattr(e, 'code'):
        print('The server couldn\'t fulfill the request.')
        print('Error code: ', e.code)
else:
    zfp = zlib.decompress(response.read(), 15 + 32)
    soup = BeautifulSoup(zfp, 'html.parser')
    #print(soup.prettify())
    load_image_script = None
    for script in soup.find_all('script'):
        for content in script.contents:
            pos = content.find("registerMainWindow")
            if pos > 0:
                load_image_script = content
    if load_image_script == None:
        print("We could not find the image...")
        sys.exit()
    pos = load_image_script.find("registerMainWindow")
    image_start = load_image_script.find("\"", pos)
    image_end = load_image_script.find("\"", image_start + 1)
    image_url = load_image_script[image_start + 1:image_end])
    if image_url == None:
        print("Something wrong with image url")
        sys.exit()
