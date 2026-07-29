# how to install
## from releases gape
1. download .tar archive
2. unpack it somewhere
3. give install.sh rights to run `chmod +x install.sh`
4. run install.sh `./install.sh` (require sudo rights)
## from source
1. if you don't have xmake, install it 
сurl installation - `Bash <(curl -fsSL https://raw.githubusercontent.com/tboox/xmake/master/scripts/get.sh)`
1. clone repo `git clone https://github.com/metw0/qsort.git`
2. move into repo's folder `cd qsort/`
3. build it with xmake `xmake`
4. move binary to /usr/local/bin/ `sudo mv qsort /usr/local/bin/`

# how to use
xmake really easy to use, you just need to know 3 flags
### -w or --where
this flag is used for declare where qsort gonna sort your files
like `/home/user/Documents` etc.
### -t or --type
this flag is used for declare type of sorting
like `name` to sort by name, `ext` to sort by extension and `date` to sort by last modification date
### -d or --df
this flag is used for declare distinctive feature (df)
like `some_file_name` for name type, `.txt` for ext type and `yyyy-mm-dd` for date type
### example
`qsort -w /home/user/Documents -t ext --df .txt`
this command gonna put all .txt files from directory where you start command
to directory in -w option (/home/user/Documents in this example)

# features
in feature I want to add: 
1. edit mode, which can delete/create files etc.

if you really like qsort, you can support me just sending feedback <3
