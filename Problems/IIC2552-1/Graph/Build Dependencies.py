n = int(input())
dependencies = {}
for i in range(n):
  filename, file_dependencies = input().split(':')
  file_dependencies = list(map(lambda x: x.strip(), file_dependencies.split()))
  dependencies[filename] = file_dependencies

print(dependencies)