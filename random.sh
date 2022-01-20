for i in 200 300 400 500 600 700 800 900 1000
    do
    for time in $(seq 1 5)
        do
            ./a.exe $i data_$i\_$time.txt connect_$i\_$time.txt
            sleep 1
        done
    done