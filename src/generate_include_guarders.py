import os
import sys

if __name__ == "__main__":
    walk_dir = "."
    project = "DOODLEGAMEENGINE"
    ifndef = "#ifndef "
    define = "#define "
    endif = "#endif //"

    print("walk_dir = " + walk_dir)
    print("walk_dir (absolute) = " + os.path.abspath(walk_dir))

    for root, subdirs, files in os.walk(walk_dir):

        for filename in files:
            if filename[-3:] != "cpp" and filename[-2:] != "py":
                c = project + "_" + \
                    os.path.join(os.path.relpath(root), filename)\
                        .replace("/", "_")\
                        .replace(".", "_")\
                        .upper()
                print("\t- %s %s" % (filename, c))
                file_path = os.path.join(root, filename)
                print(file_path)

                ls = []

                with open(file_path, "r") as f:
                    for line in f:
                        if line.startswith(ifndef + project):
                            ls.append(ifndef + c + "\n")
                        elif line.startswith(define + project):
                            ls.append(define + c + "\n")
                        elif line.startswith(endif + project):
                            ls.append(endif + c + "\n")
                        else:
                            ls.append(line)

                with open(file_path, "w") as f:
                    for l in ls:
                        f.write(l)
