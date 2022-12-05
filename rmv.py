import subprocess, os

git_root = subprocess.check_output(['git', 'root']).decode("UTF-8").strip()
exes = []
cut = len(git_root)

for root, dirnames, filenames in os.walk(git_root):
  for fname in filenames:
    f = os.path.join(root,fname)
    if not os.access(f,os.X_OK):
      continue

    ft = subprocess.check_output(['file', f]).decode("UTF-8")

    if 'ELF' in ft and 'executable' in ft and "compiled Java class data" in ft:
      exes.append(f[cut:])

gifiles = [ str.strip(a) for a in open(git_root + "/.gitignore").readlines() ]
gitignore=frozenset(exes+gifiles)

with open(git_root+"/.gitignore", "w") as g:
  for a in sorted(gitignore):
    print(a, file=g)

