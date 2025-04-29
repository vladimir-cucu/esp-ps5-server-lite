// @ts-check

const CUSTOM_ACTION_APPCACHE_REMOVE = "appcache-remove";

/**
 * @typedef {Object} PayloadInfo
 * @property {string} displayTitle
 * @property {string} description
 * @property {string} fileName - path relative to the payloads folder
 * @property {string} author
 * @property {string} projectSource
 * @property {string} binarySource - should be direct download link to the included version, so that you can verify the hashes
 * @property {string} version
 * @property {string[]?} [supportedFirmwares] - optional, these are interpreted as prefixes, so "" would match all, and "4." would match 4.xx, if not set, the payload is assumed to be compatible with all firmwares
 * @property {number?} [toPort] - optional, if the payload should be sent to "127.0.0.1:<port>" instead of loading directly, if specified it'll show up in webkit-only mode too
 * @property {string?} [customAction]
 */

/**
 * @type {PayloadInfo[]}
*/
const payload_map = [
  {
    displayTitle: "Byepervisor HEN",
    description: "FPKG enabler",
    fileName: "byepervisor.elf.gz",
    author: "SpecterDev, ChendoChap, flatz, fail0verflow, Znullptr, kiwidog, sleirsgoevy, EchoStretch, LightningMods, BestPig, zecoxao", 
    projectSource: "https://github.com/EchoStretch/Byepervisor",
    binarySource: "https://github.com/EchoStretch/Byepervisor/actions/runs/14004003762",
    version: "84164bb",
    supportedFirmwares: ["1.00", "1.01", "1.02", "1.12", "1.14", "2.00", "2.20", "2.25", "2.26", "2.30", "2.50", "2.70"],
    toPort: 9021
  },
  {
    displayTitle: "etaHEN",
    description: "AIO Homebrew enabler",
    fileName: "etaHEN-2.1b.bin.gz",
    author: "LightningMods, Buzzer, sleirsgoevy, ChendoChap, astrelsky, illusion, CTN, SiSTR0, Nomadic",
    projectSource: "https://github.com/etaHEN/etaHEN",
    binarySource: "https://github.com/etaHEN/etaHEN/releases/download/2.1B/etaHEN.bin",
    version: "2.1b",
    toPort: 9021
  }
];
