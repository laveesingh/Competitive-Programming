

class Report:

    def __init__(self, report):
        self.report = report

    def is_valid(self):

        def flip(expected):
            if expected == 'H':
                return 'T'
            return 'H'

        self.report = self.report.replace('.', '')
        if not self.report:
            return "Valid"
        if (not self.report.startswith('H')) or (not self.report.endswith('T')):
            return "Invalid"
        expected = 'H'
        for s in self.report:
            if s == expected:
                expected = flip(expected)
            else:
                return "Invalid"
        return "Valid"


for _ in xrange(input()):
    n = input()
    report = raw_input()
    print Report(report).is_valid()
